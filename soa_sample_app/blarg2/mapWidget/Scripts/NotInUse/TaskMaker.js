function addTask(latlng, numPts, tempID, tType, div) {
    log(latlng);
    log(numPts);
    log(tempID);
    log(tType);
    log(div);
    log(myDiv);
	var thisId;
	var color;
	var tArray;
	log("Task point 1");
	if (div == myDiv) {
	    log("div == myDiv");
        return;
	}
	else if (div == "EMS") {
	    tId = EMSTaskId;
	    EMSTaskId++;
	    color = '#ffffff';
	    tArray = EMSTaskArray;
	}
	else if (div == "HAZMAT") {
	    tId = HAZMATTaskId;
	    HAZMATTaskId++;
	    color = '#dddddd';
	    tArray = HAZMATTaskArray;
	}
	else if (div == "POLICE") {
	    tId = POLICETaskId;
	    POLICETaskId++;
	    color = '#dddddd';
	    tArray = POLICETaskArray;
	}
	else {
	    log("Got a bad division name.");
	    log(div);
	}
    log("Task point 2");
	var ll = latlng.split(" ");
	
	
	var coords = new Array();
	var x;
	var y;
    log("Task point 3");
	for (var i = 0; i < numPts; i++){
		x = parseFloat(ll[i]);
		i++;
		y = parseFloat(ll[i]);
		coords.push(new google.maps.LatLng(x, y));
	};

    log("here in the task thingy");
	var ppgon = new google.maps.Polygon({
		paths: coords,
	    strokeColor: color,
	    strokeOpacity: 0.75,
	    strokeWeight: 2,
	    fillColor: color,
	    fillOpacity: 0.5
    });

    ppgon.setMap(map);
	
	
    var temp = new task(ppgon, tType, tId, div);
    tArray.push(temp);
    temp = null;
    log("Sending task to Qt");
    taskManifest.taskSentToJS(tempID, tId, tType);
};



function addLineTask(latlng, numPts, tempID, tType, div) {
    log(latlng);
    log(numPts);
    log(tempID);
    log(tType);
    log(div);
    log(myDiv);
    var thisId;
    var color;
    var tArray;
    log("Task point 1");
    if (div == myDiv) {
        log("div == myDiv");
        return;
    }
    else if (div == "EMS") {
        tId = EMSTaskId;
        EMSTaskId++;
        color = '#ff0000';
        tArray = EMSTaskArray;
    }
    else if (div == "HAZMAT") {
        tId = HAZMATTaskId;
        HAZMATTaskId++;
        color = '#ffff00';
        tArray = HAZMATTaskArray;
    }
    else if (div == "POLICE") {
        tId = POLICETaskId;
        POLICETaskId++;
        color = '#0000ff';
        tArray = POLICETaskArray;
    }
    else {
        log("Got a bad division name.");
        log(div);
    }
    log("Task point 2");
    var ll = latlng.split(" ");


    var coords = new Array();
    var x;
    var y;
    log("Task point 3");
    for (var i = 0; i < numPts; i++) {
        x = parseFloat(ll[i]);
        i++;
        y = parseFloat(ll[i]);
        coords.push(new google.maps.LatLng(x, y));
    };

    log("here in the task thingy");
    var pLine = new google.maps.PolyLine({
        paths: coords,
        strokeColor: color,
        strokeOpacity: 0.75,
        strokeWeight: 2.5
    });

    pLine.setMap(map);


    var temp = new task(pLine, tType, tId, div);
    tArray.push(temp);
    log("Sending task to Qt");
    taskManifest.taskSentToJS(tempID, tId, tType);
};

function deleteTempTask(){
	tempTask.poly.setMap(null);
};


function addTPTask(tempID, tType, div) {
    log("Task point 0");
    var thisId;
    var color;
    var tArray;
    log("Task point 1");
    if (div == myDiv) {
        log("div == myDiv");
        return;
    }
    else if (div == "EMS") {
        tId = EMSTaskId;
        EMSTaskId++;
        color = '#ffffff';
        tArray = EMSTaskArray;
    }
    else if (div == "HAZMAT") {
        tId = HAZMATTaskId;
        HAZMATTaskId++;
        color = '#dddddd';
        tArray = HAZMATTaskArray;
    }
    else if (div == "POLICE") {
        tId = POLICETaskId;
        POLICETaskId++;
        color = '#dddddd';
        tArray = POLICETaskArray;
    }
    else {
        log("Got a bad division name.");
        log(div);
    }

    log("here in the task thingy");
    var ppgon = tempTask.poly;
    
    
    var temp = new task(ppgon, tType, tId, div);
    tArray.push(temp);
    temp = null;
    log("Sending task to Qt");
    taskManifest.taskSentToJS(tempID, tId, tType);
    TempTask = null;
};
