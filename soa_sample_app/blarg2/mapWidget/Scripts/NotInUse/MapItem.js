
var detailsWdth = 60;
var normalWdth = detailsWdth * 0.7;
var residueWdth = detailsWdth * 0.4;
var groupingWdth = detailsWdth * 0.15;
var timeOut = 75;
var tTextHeight = 10;
var textHeight = 8;
var font = "px Verdana";





function static_icon(options) { 
    var item = new google.maps.Marker();
    item.setOptions(options);
    itemArray[item.iid] = item;
    return item;
};

function static_icon_options_template(map, iid, position, url, msg) {
    return {
        map: map,
        position: position,                        
        icon: {
            url: url,
            scaledSize: new google.maps.Size(normal, normal, 'px', 'px'),
        },
        object_type: object_type.STATIC_ICON,
        msg: msg
    }
};

