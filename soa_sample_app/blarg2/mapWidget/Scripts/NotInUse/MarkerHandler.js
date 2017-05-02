//*****************************************************************************
//Functions to handle the marker objects created by ObjectMarker.js 
//*****************************************************************************


 function removeMarker(grObj, handleID) {
        var iid = handleID + 0;
        temp = markerArray[iid];
        temp.gMarker.setMap(null);
    };


    function fromQt(grObj, lat, lng, handleID, msg, iimage) {
        //log("fromQT " + lat + " " + lng + " " + handleID + " " + msg + " " + iimage);
        //log(typeof msg);
        var xx = lat + 0.0;
        var yy = lng + 0.0;
        var iid = handleID + 0;
        var sg = new String(msg);
        //log(typeof sg + " '" + sg + "'");
        var mmsg = sg.split("|");
        for (var q = 0; q < mmsg.length; q++)
            //log(mmsg[q]);       
        var imName;
        imName = iimage;
        var llatLlng2 = new google.maps.LatLng(xx, yy);
        var ttemp2 = addMarker(grObj, llatLlng2, iid, mmsg, imName);
        markerArray[iid] = ttemp2;
        ttemp2.POI.seeIcon(ttemp2.POI);
    };


    function addMarker(expObj, latLng1, iid, mmsg, iimage) {
        expObj.show();
        temp = new Marker({
            iconID: iid,
            grouper: expObj,
            msg: mmsg,
            image: iimage,
            map: map,
            pos: latLng1
        });
        addListeners(temp, expObj);

        return temp;
    };

    function addListeners(tMarker, expObj) {
        //log('adding Listeners');
        google.maps.event.addListener(tMarker.gMarker, 'mouseover', function () {
            expObj.hoverItem(tMarker.POI.getID())
        });

        google.maps.event.addListener(tMarker.gMarker, 'mouseout', function () {
            expObj.unhoverItem(tMarker.POI.getID())
        });

        google.maps.event.addListener(tMarker.gMarker, 'click', function () {
            //expObj.clickItem(tMarker.POI.getID())
            expObj.clickItem(tMarker.POI.getID())
        });
    };

//Uncomment this to see animation (comment out duplicate functions below)
//    function toDetails(grObj, iid) {
//        log("toDetails " + iid);
//        temp = markerArray[iid];
//        temp.POI.toDetails(temp.POI, temp.gMarker);
//    };

//    function toNormal(grObj, iid) {
//        log("toNormal " + iid);
//        temp = markerArray[iid];
//        temp.POI.toNormal(temp.POI, temp.gMarker);
//    };

//    function toResidue(grObj, iid) {
//        log("toResidue " + iid);
//        temp = markerArray[iid];
//        temp.POI.toResidue(temp.POI, temp.gMarker);
//    };

//    function toGrouping(grObj, iid) {
//        log("toGrouping " + iid);
//        temp = markerArray[iid];
//        temp.POI.forGrouping(temp.POI, temp.gMarker);
    //    };

    function toDetails(grObj, iid) {
        //log("toDetails " + iid);
        temp = markerArray[iid];
        temp.POI.details(temp.POI, temp.gMarker);
    };

    function toNormal(grObj, iid) {
        //log("toNormal " + iid);
        temp = markerArray[iid];
        temp.POI.normal(temp.POI, temp.gMarker);
    };

    function toResidue(grObj, iid) {
        //log("toResidue " + iid);
        temp = markerArray[iid];
        temp.POI.residue(temp.POI, temp.gMarker);
    };

    function toGrouping(grObj, iid) {
        //log("toGrouping " + iid);
        temp = markerArray[iid];
        temp.POI.forGrouping(temp.POI, temp.gMarker);
    };