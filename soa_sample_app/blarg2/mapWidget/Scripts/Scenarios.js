/*******************************************************************************
 * Scenario Convenience Functions
 * - Usage is demonstrated in sample scenario files
 *******************************************************************************/
var trigger = google.maps.event.trigger;
var LatLng = google.maps.LatLng;
function timed_event(time, fn) {
    setTimeout(fn, time);
};

function timed_log(time, text) {
    timed_event(time, function() { log(text); });
};

function swap_icon(item, icon_url) {
    item.setIcon({
        url: icon_url,
        scaledSize: item.icon.scaledSize
    });
};

function swap_color(item, color) {
    item.setOptions({
        fillColor: color
    });
};

function add_robot(lat, lng, affiliation, type, iid) {
    log(iid);
    trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(lat, lng), affiliation, type, iid)); 
};

function add_group_icon(iid, lat, lng, affiliation, iype) { //map, position, iype, iid, , iitle, msg;
   trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(lat, lng), affiliation, iype, iid));
}; 

function add_mapItem(lat, lng, id, url) {
	if (url == 1)
		pUrl = "images/Village.png";
    trigger(map, 'add_item', static_icon, static_icon_options_template(map, id, new LatLng(lat, lng), url, 'msg')); 
};
/*
	Subtleties about scenario writing:
	Explicitly create global variables using window.<var_name>?
	EVERYTHING should be timed
*/
