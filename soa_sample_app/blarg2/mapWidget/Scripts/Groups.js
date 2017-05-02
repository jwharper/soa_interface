var Group = function (pGon, tId, gIc) //Must receive ID, map, lattitude, and longitude
{
	this.Id = tId;
	this.pGon = pGon;
	this.icon = gIc;
	this.icon.speed= 0.3;
	//log("made a group");
	//log(this.Id);
	//log(this.debugId);
	return this;
};

function boom() {
	log("BOOMBOOMBOOMBOOM");
}
function removeTask(tId) {
	var iid = tId + 0;
	myTaskArray[iid].icon.setMap(null);
	myTaskArray[iid].icon = null;
	myTaskArray[iid].pGon.setMap(null);
	myTaskArray[iid] = null;
};
function removeGroup(expObj, tId) {
	var str = "removeGroup(";
	str += expObj;
	str += ", ";
	str += tId;
	str += ")";
	log(str);

	var iid = tId + 0;
	//log("groupArray length:")
	//log(groupArray.length);
	//log("removeGroup");
	//log(iid);
	groupArray[iid].icon.setMap(null);
	groupArray[iid].icon = null;
	groupArray[iid].pGon.setMap(null);
	groupArray[iid] = null;
};
function updateGroup(expObj, numId, idString, tId, hullColor) {
	//var str = "removeGroup(";
	//str += expObj;
	//str += ", ";
	//str += tId;
	//str += ")";
	//log(str);

	var iid = tId + 0;
	log("updateGroup");
	//log("tId (from Qt):");
	//log(tId);
	//log("iid (JavaScript int):")
	//log(iid);
	//var butt = groupArray[iid];
	//log("Grouping Icon's debugId:")
	//log(butt.debugId);
	var gIc = groupArray[iid].icon;
	groupArray[iid].pGon.setMap(null);
	groupArray[iid] = null;

	var hullPoints = new Array();
	var groupingMarkers = new Array();
	var idArray = idString.split(" "); 
	for (var j = 0; j < numId; j++) {
		groupingMarkers[j] = robot_array[parseInt(idArray[j])];
	};
	var numP = numId;
	convexHull(groupingMarkers, numP, hullPoints);
	var pgonPoints = new Array();
	var QtPts = new Array();
	var centLat = 0;
	var centLng = 0;
	//log("centroid stuff:");
	for (var i = 0; i < hullPoints.length; i++) {
		//log(hullPoints[i].lng());
		pgonPoints.push(new google.maps.LatLng(hullPoints[i].lat(), hullPoints[i].lng()));
		if (i < hullPoints.length)
		{
			centLat += hullPoints[i].lat();
			centLng += hullPoints[i].lng();
		}
		//QtPts.push(hullPoints[i].lat());
		//QtPts.push(hullPoints[i].lng());
	};
	//log(hullPoints.length);
	centLat = centLat/(hullPoints.length);
	centLng= centLng/(hullPoints.length);
	var pgon = new google.maps.Polygon({
		paths: pgonPoints,
		strokeColor: hullColor,
		strokeOpacity: 0.8,
		strokeWeight: 2,
		fillColor: hullColor,
		fillOpacity: 0.35,
		zIndex: 1
	});
	////log(QtPts.length);
	pgon.setMap(map);
	//gIc.updatePosition(new LatLng(centLat, centLng))	
	moveIt(gIc, centLat, centLng);
	gIc.msg1 = [numP, " ", gIc.rtype, 's'].join();
	log(gIc.groupIcon);
	var tGroup = new Group(pgon, iid, gIc);
	groupArray[iid] = tGroup;
	var oId = tGroup.Id;
	//log("groupArray length:")
	//log(groupArray.length);
	//log("tGroup Id:");
	//log(oId);
	//log("iid:");
	//log(iid);
	//var QtPts = "WhamWhamWham!!!";
	var str = "item, receiveHullPoints, " + QtPts + ", " + iid;
	//log("end updateGroup");
	webView.fromJS(str);
};

function makeGroup(expObj, numId, idString, tiid, hullColor, affiliation, rype, gId) {
	tId = tiid + 0;
	log("makeGroup xxx");
	var hullPoints = new Array();
	var groupingMarkers = new Array();
	var idArray = idString.split(" "); 
	for (var j = 0; j < numId; j++) {
		groupingMarkers[j] = robot_array[parseInt(idArray[j])];
	};
	var temp = groupingMarkers[0];
	var numP = numId;
	var centLat = 0;
	var centLng = 0;
	convexHull(groupingMarkers, numP, hullPoints);
	var pgonPoints = new Array();
	var QtPts = new Array();
	//log("centroid stuff:");
	for (var i = 0; i < hullPoints.length; i++) {
		//log(hullPoints[i].lng());
		pgonPoints.push(new google.maps.LatLng(hullPoints[i].lat(), hullPoints[i].lng()));
		if (i < hullPoints.length)
		{
			centLat += hullPoints[i].lat();
			centLng += hullPoints[i].lng();
		}
	};
	centLat = centLat/(hullPoints.length);
	centLng= centLng/(hullPoints.length);
	var pgon = new google.maps.Polygon({
		paths: pgonPoints,
		strokeColor: hullColor,
		strokeOpacity: 0.8,
		strokeWeight: 2,
		fillColor: hullColor,
		fillOpacity: 0.35,
		zIndex: 1
	});
	pgon.setMap(map);
	var ttitle = [temp.rtype, 'Group'].join(' ');
	add_group_icon(gId, centLat, centLng, temp.affiliation, temp.rtype);
	var gIc = robot_array[gId];
	log("calculated lat, lng: " + centLat + ", " + centLng);
	gIc.groupIcon = 1;
	var tGroup = new Group(pgon, tId, gIc);
	groupArray[tId] = tGroup;
	set_visual_state2(gIc, 'normal')
	var str = "item, receiveHullPoints, " + QtPts + ", " + tId;
	webView.fromJS(str);
};


function convexHull(groupedMarkers, numPoints, hullPoints) {
	////log("convexHull");
	// Use Google Maps’ point class or any point class with x() and y() methods defined
	var points = [];
	//var hullPoints = [];
	var hullPoints_size;
	var pad = 0.0000255435;
	// Add a couple sample points to the array
	for (var i = 0; i < numPoints; i++) {
		points.push(new google.maps.LatLng(groupedMarkers[i].position.lat() + pad, groupedMarkers[i].position.lng() + pad));
		points.push(new google.maps.LatLng(groupedMarkers[i].position.lat() + pad, groupedMarkers[i].position.lng() - pad));
		points.push(new google.maps.LatLng(groupedMarkers[i].position.lat() - pad, groupedMarkers[i].position.lng() + pad));
		points.push(new google.maps.LatLng(groupedMarkers[i].position.lat() - pad, groupedMarkers[i].position.lng() - pad));
		//log(groupedMarkers[i].gMarker.getPosition().lat());
	}
	// Sort the points by X, then by Y (required by the algorithm)
	points.sort(sortPointY);
	points.sort(sortPointX);
	// Calculate the convex hull
	// Takes: an (1) array of points with x() and y() methods defined
	//          (2) Size of the points array
	//          (3) Empty array to store the hull points
	// Returns: The number of hull points, which may differ the the hull points array’s size
	hullPoints_size = chainHull_2D(points, points.length, hullPoints);
	//log(hullPoints_size);
	//log(hullPoints.length);
//	for (var j = 0; j < hullPoints.length; j++) {
//		log(hullPoints[j].lng());
//	}
	//log("that was log(hullPoints[j].lng;");
	//log(hullPoints.length);
};

