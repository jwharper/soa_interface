//Get rid of integer indexing in lists/arrays. Everything should use pointer
//s

var detailsWdth = 60;
var normalWdth = detailsWdth * 0.7;
var residueWdth = detailsWdth * 0.4;
var groupingWdth = detailsWdth * 0.15;
var timeOut = 75;
var tTextHeight = 10;
var textHeight = 8;
var font = "px Verdana";


var POI = function (options) {
    "use strict";
    this.ID = options.iconID;
    this.grouper = options.grouper || -1;
    this.groupIndex = -1; 		//Index position of the group to which this marker's marker has been assigned.
    this.wdth = normalWdth;
    this.canvas = document.createElement("canvas");
    this.canvas.width = this.wdth;
    this.canvas.height = this.wdth;
    this.ctx = this.canvas.getContext("2d");
    this.image = new Image();
    this.image.src = options.image || "C:/Source/hmt-branch/widgets/gmapwidget/Scripts/gathersamples.png";
    this.shrink = 0.95;
    this.grow = 1.05;
    this.pulse = this.shrink;
    this.state = "undefined";
    this.previousState = "undefined";
    this.centerX = 0;
    this.centerY = 0;
    this.msg = new Array();
    this.msg = options.msg;
    if (this.msg.length < 1 || this.msg[0] == "")
        this.msg[0] = "This space for rent."
    //log('POI done');
    return this;
};



var scaleMixins = function () { };

scaleMixins.prototype =
{
    throb: function (obj, gm) {
        obj.clear(obj, obj.wdth, obj.wdth);
        if (obj.state == "forGrouping" && obj.pulse == obj.grow)
            obj.residueToGroup(obj, gm);
        else if (obj.state == "residue" && obj.pulse == obj.grow)
            obj.normalToResidue(obj, gm);
        else if (obj.state == "normal" && obj.pulse == obj.grow)
            obj.detailsToNormal(obj, gm);
        else if (obj.state == "details" && obj.pulse == obj.grow)
            obj.pulse = obj.shrink
        else if (obj.state == "details" && obj.pulse == obj.shrink)
            obj.detailsToNormal(obj, gm);
        else if (obj.state == "normal" && obj.pulse == obj.shrink)
            obj.normalToResidue(obj, gm);
        else if (obj.state == "residue" && obj.pulse == obj.shrink)
            obj.residueToGroup(obj, gm);
        else if (obj.state == "forGrouping" && obj.pulse == obj.shrink) {
            obj.pulse = obj.grow;
            obj.throb(obj, gm);
        }
        else
            obj.ctx.strokeStyle = "#FF0000";
        obj.ctx.strokeRect(0, 0, obj.canvas.width, obj.canvas.height);
    },


    toDetails: function (obj, gm) {
        if (obj.state == "details")
            return;
        obj2 = obj;
        gm2 = gm;
        if (obj2.state == "normal")
            obj2.pulse = obj2.grow;
        if (obj2.state == "forGrouping")
            obj2.toResidue(obj2, gm2);
        if (obj2.state == "residue")
            obj2.toNormal(obj2, gm2);
        setTimeout(function () {
            obj2.wdth = obj2.wdth * obj2.pulse;
            obj2.clear(obj2, obj2.wdth, obj2.wdth);
            obj2.ctx.globalAlpha = 1;
            obj2.ctx.drawImage(obj2.image, 0, 0, obj2.wdth, obj2.wdth);
            obj2.setCenter(obj2);
            //gm2.setIcon(obj2.canvas.toDataURL());
            gm2.setIcon(obj2.seeIcon(obj2));
            if ((obj.wdth < detailsWdth)) {
                obj2.toDetails(obj2, gm2);
            }
            else {
                obj2.details(obj2, gm2);
            }
        }, timeOut)
    },


    toNormal: function (obj, gm) {
        if (obj.state == "normal")
            return;
        obj2 = obj;
        gm2 = gm;
        if (obj2.state == "details")
            obj2.pulse = obj2.shrink;
        else if (obj2.state == "residue")
            obj2.pulse = obj2.grow;
        else
            obj2.toResidue(obj2, gm2);
        setTimeout(function () {
            var aleph;
            obj2.wdth = obj2.wdth * obj2.pulse;
            if (obj2.wdth <= normalWdth * 0.667)
                aleph = 0.65;
            else
                aleph = obj2.wdth * 0.01 + 0.25;
            obj2.clear(obj2, obj2.wdth, obj2.wdth);
            obj2.ctx.globalAlpha = aleph;
            obj2.ctx.drawImage(obj2.image, 0, 0, obj2.wdth, obj2.wdth);
            obj2.setCenter(obj2);
            //gm2.setIcon(obj2.canvas.toDataURL());
            gm2.setIcon(obj2.seeIcon(obj2));
            if ((obj2.wdth > residueWdth && obj2.pulse == obj2.shrink) || (obj2.wdth < normalWdth && obj2.pulse == obj2.grow)) {
                obj2.toNormal(obj2, gm2);
            }
            else {
                obj2.normal(obj2, gm2);
            }
        }, timeOut)
    },


    toResidue: function (obj, gm) {
        if (obj.state == "residue")
            return;
        obj2 = obj;
        gm2 = gm;
        if (obj2.state == "details")
            obj2.toNormal(obj2, gm2);
        else if (obj2.state == "normal")
            obj2.pulse = obj2.shrink;
        else
            obj2.pulse = obj2.grow;
        setTimeout(function () {
            obj2.wdth = obj2.wdth * obj2.pulse;
            obj2.clear(obj2, obj2.wdth, obj2.wdth);
            obj2.ctx.globalAlpha = 0.65;
            obj2.ctx.drawImage(obj2.image, 0, 0, obj2.wdth, obj2.wdth);
            obj2.setCenter(obj2);
            //gm2.setIcon(obj2.canvas.toDataURL());
            gm2.setIcon(obj2.seeIcon(obj2));
            if ((obj.wdth > residueWdth && obj.pulse == obj.shrink) || (obj.wdth < residueWdth && obj.pulse == obj.grow)) {
                obj2.toResidue(obj2, gm2);
            }
            else {
                obj2.residue(obj2, gm2);
            }
        }, timeOut)
    },

    clear: function (obj, w, h) {
        width = w;
        height = h || w;
        obj.ctx.clearRect(0, 0, obj.canvas.width, obj.canvas.height);
        obj.canvas.width = width;
        obj.canvas.height = height;
        //Uncomment the following to illustrate that the canvas itself resizes
        //obj.ctx.strokeStyle="#FF0000";
        //obj.ctx.strokeRect(0,0,obj.canvas.width, obj.canvas.height);
    },

    seeIcon: function (obj) {
        var icon = new google.maps.MarkerImage
			(
				obj.canvas.toDataURL(),
				new google.maps.Size(obj.canvas.width, obj.canvas.height), //Size
				new google.maps.Point(0, 0), 							//Origin
				new google.maps.Point(obj.centerX, obj.centerY)				//anchor; centerpoint, usually
			);
        return icon;
    },

    setCenter: function (obj) {
        obj.centerX = obj.canvas.width / 2;
        obj.centerY = obj.canvas.height / 2;
    },

    details: function (obj, gm) {
        //if (obj.state == "forGrouping")
        var flagWidth = 0;
        //console.log(flagWidth);
        var titleFont = tTextHeight + "px Verdana";
        var bodyFont = textHeight + "px Verdana"
        obj.ctx.font = titleFont;
        flagWidth = obj.ctx.measureText(obj.msg[0]).width;
        flagWidth = flagWidth + detailsWdth * 1.30;
        //console.log(flagWidth);
        obj.ctx.font = bodyFont;
        for (var j = 1; j < obj.msg.length; j++) {
            if (flagWidth < (obj.ctx.measureText(obj.msg[j]).width + detailsWdth * 1.18)) {
                flagWidth = obj.ctx.measureText(obj.msg[j]).width + detailsWdth * 1.18;
                //console.log(flagWidth);
            }
        }
        flagWidth = flagWidth + 10;
        //console.log(flagWidth);
        var flagLeft = detailsWdth * 0.66;
        var flagTop = detailsWdth * 0.01;
        var flagHeight = tTextHeight * 1.6 + (obj.msg.length - 1) * (textHeight * 1.2);   //detailsWdth * (0.3 + ((obj.msg.length - 1) * 0.15));
        var clearHeight = 2 + detailsWdth * 1.17;
        if (clearHeight < flagHeight)
            clearHeight = flagHeight + 2;
        var clearWidth = detailsWdth * 0.66 + flagWidth + 2;
        obj.clear(obj, clearWidth, clearHeight);
        obj.ctx.beginPath();
        obj.ctx.arc(detailsWdth * 0.06, detailsWdth * 1.11, detailsWdth * 0.05, 0, 2 * Math.PI);
        obj.ctx.moveTo(detailsWdth * 0.06, detailsWdth * 1.06);
        obj.ctx.lineTo(detailsWdth * 0.06, detailsWdth * 1.16);
        obj.ctx.moveTo(detailsWdth * 0.01, detailsWdth * 1.11);
        obj.ctx.lineTo(detailsWdth * 0.11, detailsWdth * 1.11);
        obj.ctx.moveTo(detailsWdth * 0.06, detailsWdth * 1.16);
        obj.ctx.lineTo(flagLeft, flagTop + flagHeight);
        obj.ctx.moveTo(detailsWdth * 0.06, detailsWdth * 1.06);
        obj.ctx.lineTo(flagLeft, flagTop);
        obj.ctx.stroke();
        obj.ctx.fillStyle = '#FFFFFF';
        obj.ctx.fillRect(flagLeft, flagTop, flagWidth, flagHeight);
        obj.ctx.fillStyle = "#000000";
        var nextLine = flagTop + (tTextHeight * 1.3);
        obj.ctx.font = titleFont;
        obj.ctx.fillText(obj.msg[0], detailsWdth * 1.30, nextLine);
        obj.ctx.font = bodyFont;
        nextLine = nextLine + tTextHeight + textHeight * 0.2;
        for (var i = 1; i < obj.msg.length; i++) {
            obj.ctx.fillText(obj.msg[i], detailsWdth * 1.18, nextLine);
            nextLine = nextLine + textHeight * 1.2;
        }
        obj.ctx.strokeRect(flagLeft, flagTop, flagWidth, flagHeight);
        obj.ctx.drawImage(obj.image, detailsWdth * 0.16, detailsWdth * 0.01, detailsWdth * 1.00, detailsWdth * 1.00);
        obj.state = "details";
        obj.centerX = detailsWdth * 0.06;
        obj.centerY = detailsWdth * 1.11;
        if (gm) {
            gm.setIcon(obj.seeIcon(obj));
            gm.setZIndex(3);
        }
    },

    normal: function (obj, gm) {
        obj.clear(obj, normalWdth);
        obj.ctx.globalAlpha = 1;
        //        if (!obj.ctx)
        //        { console.log("No obj.ctx"); }
        //        if (obj.image)
        //        { console.log(obj.image); }
        obj.ctx.drawImage(obj.image, 0, 0, normalWdth, normalWdth);
        obj.state = "normal";
        obj.setCenter(obj);
        if (gm) {
            gm.setIcon(obj.seeIcon(obj));
            gm.setZIndex(2);
        }
    },

    residue: function (obj, gm) {
        obj.clear(obj, residueWdth);
        obj.ctx.globalAlpha = 0.60;
        obj.ctx.drawImage(obj.image, 0, 0, residueWdth, residueWdth);
        obj.state = "residue";
        obj.setCenter(obj);
        if (gm) {
            gm.setIcon(obj.seeIcon(obj));
            gm.setZIndex(2);
        }
        /*if (obj.forGrIndex >= 0)
        {
        obj.grouper.removeForGrouping(obj.grouper, obj.forGrIndex, obj.grIndex, obj.groupIndex);
        obj.forGrIndex = -1;
        }*/
    },

    forGrouping: function (obj, gm) {
        obj.clear(obj, groupingWdth);
        obj.ctx.globalAlpha = 1;
        obj.ctx.fillStyle = "Black";
        obj.ctx.fillRect(residueWdth * 0.1, residueWdth * 0.1, residueWdth * 0.8, residueWdth * 0.8);
        obj.state = "forGrouping";
        obj.setCenter(obj);
        if (gm) {
            gm.setIcon(obj.seeIcon(obj));
            gm.setZIndex(2);
        }
    },

    getID: function (obj) {
        console.info("getID function");
        console.info(this.ID.toString())
        return this.ID.toString();
    },

    rect: function (obj, x, y, w, h) {
        obj.ctx.beginPath();
        obj.ctx.rect(x, y, w, h);
        obj.ctx.closePath();
        obj.ctx.fill();
    }
};                   //End scaleMixins


//Source: http://addyosmani.com/resources/essentialjsdesignpatterns/book/#designpatternstructure
function augment(receivingClass, givingClass) {
    // provide all methods
    for (var methodName in givingClass.prototype) {

        // check to make sure the receiving class doesn't
        // have a method of the same name as the one currently
        // being processed
        if (!Object.hasOwnProperty(receivingClass.prototype, methodName)) {
            receivingClass.prototype[methodName] = givingClass.prototype[methodName];
        }
    }
}


augment(POI, scaleMixins);

var Marker = function (options) //Must receive ID, map, lattitude, and longitude
{
    this.trueLat = options.pos.lat();
    this.trueLng = options.pos.lng();
    this.POI = new POI({
        iconID: options.iconID,
        grouper: options.grouper,
        msg: options.msg,
        image: options.image,
        marker: this
    });
    this.normal(this.POI);
    var temp = this.POI;
    this.gMarker = new google.maps.Marker({
        position: options.pos,
        map: options.map,
        title: options.msg[0],
        icon: this.seeIcon(temp)
    });
    this.gMarker.setVisible(true);
    //log('gMarker');
    return this;
};

augment(Marker, scaleMixins);