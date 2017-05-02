/*******************************************************************************
 *  The static icon and its options template
 *******************************************************************************/

function static_icon(options) { 
    var item = new google.maps.Marker();
    item.setOptions(options);
    itemArray[item.iid] = item;
    return item;
};

function static_icon_options_template(map, id, position, url, msg) {
    return {
        map: map,
        iid: iid,
        position: position,                        
        icon: {
            url: url,
            scaledSize: new google.maps.Size(25, 25, 'px', 'px'),
        },
        object_type: object_type.STATIC_ICON,
        msg: msg
    }
};