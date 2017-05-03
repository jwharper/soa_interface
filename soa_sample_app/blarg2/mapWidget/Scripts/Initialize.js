function Dinitialize(options){

	//to limit the map 
	var x1 = clat+blat1;
	var y1 = clng+blng1;
	var x2 = clat+blat2; 
	var y2 = clng+blng2;
   	var strictBounds = new google.maps.LatLngBounds(
		new google.maps.LatLng(x2, y2),
		new google.maps.LatLng(x1, y1)
	);
	
	drawingManager = initDrawManager();
	
	var contextMenu = initRightClickMenu();

	// Listen for the dragend event
	google.maps.event.addListener(map, 'dragend', function() {
		
		if (strictBounds.contains(map.getCenter())) return;

		// We're out of bounds - Move the map back within the bounds

		var c = map.getCenter(),
		    x = c.lng(),
		    y = c.lat(),
		 maxX = strictBounds.getNorthEast().lng(),
		 maxY = strictBounds.getNorthEast().lat(),
		 minX = strictBounds.getSouthWest().lng(),
		 minY = strictBounds.getSouthWest().lat();

		if (x < minX) x = minX;
		if (x > maxX) x = maxX;
		if (y < minY) y = minY;
		if (y > maxY) y = maxY;

		map.setCenter(new google.maps.LatLng(clat,clng));
		});

   // Limit the zoom level
	google.maps.event.addListener(map, 'zoom_changed', function() {
		if (map.getZoom() < minZoom) map.setZoom(minZoom);
	});



	window.addEventListener('keypress', function (e) {
		if (e.keyCode == 116) {
			drawingManager.setDrawingMode(google.maps.drawing.OverlayType.POLYGON);
		}
	});

	window.addEventListener('keypress', function (e) {
		if (e.keyCode !== 116) {
			drawingManager.setDrawingMode(null);
		}
	});

	google.maps.event.addListener(drawingManager, 'polygoncomplete', function (e) {
		tempTask = e;
        var p = tempTask.getPath();
        var sendMe = p.getAt(0).toString();
        for (var i = 1; i < p.getLength(); i++) {
            sendMe += ", ";
            sendMe += p.getAt(i).toString();
        }
        //log(sendMe);
        //log("in Initialize");
        webView.recvFromJS(sendMe);  
        drawingManager.setDrawingMode(null);  
	});

	google.maps.event.addListener(drawingManager, 'polylinecomplete', function (e) {		
		tempTask = e;
        var p = tempTask.getPath();
        var sendMe = p.getAt(0).toString();
        for (var i = 1; i < p.getLength(); i++) {
            sendMe += ", ";
            sendMe += p.getAt(i).toString();
        }
        //log(sendMe);
        //log("in Initialize");
        webView.recvFromJS(sendMe);
        drawingManager.setDrawingMode(null);    
	});

	mask = maskInit();
};



/******************************************************************************
** This function creates the context menu that appears when the user right
** clicks on the map. It returns the context menu that has been created.
** The context menu code used is found at 
** //http://code.martinpearman.co.uk/googlemapsapi/contextmenu/1.0/
******************************************************************************/
function initRightClickMenu(){
    var contextMenuOptions = {};
    contextMenuOptions.classNames = { menu: 'context_menu', menuSeparator: 'context_menu_separator' };
    // create an array of ContextMenuItem objects 
    var menuItems = [];
    
    // a menuItem with no properties will be rendered as a separator
    menuItems.push({});
    menuItems.push({ className: 'context_menu_item', eventName: 'center_map_click', label: 'Center map here' });
    contextMenuOptions.menuItems = menuItems;

    // create the ContextMenu object 
    var contextMenu = new ContextMenu(map, contextMenuOptions);

    // display the ContextMenu on a Map right click 
    google.maps.event.addListener(map, 'rightclick', function (mouseEvent) {
        //if (drawingManager.getDrawingMode() != "NULL")
        //window.event('keypress', 27);
        //	drawingManager.setDrawingMode("NULL");
        //else
        contextMenu.show(mouseEvent.latLng);
    });
    // listen for the ContextMenu 'menu_item_selected' event 
    google.maps.event.addListener(contextMenu, 'menu_item_selected', function (latLng, eventName) {
        taskType = eventName;
        // latLng is the position of the ContextMenu 
        // eventName is the eventName defined for the clicked ContextMenuItem in the ContextMenuOptions 
        drawingManager.setOptions({
            polygonOptions: {
                fillColor: '#00ff00',
                fillOpacity: 0.75,
                strokeColor: '#00ff00',
                strokeOpacity: 1.0,
                strokeWeight: 5,
                clickable: true,
                zIndex: 1,
                editable: true
            },
            polylineOptions: {
                strokeColor: '#ffffff',
                strokeOpacity: 1,
                strokeWeight: 10,
                clickable: true,
                zIndex: 1,
                editable: true
            }
        });
        switch (eventName) {
            case 'center_map_click':
                map.panTo(latLng);
                break;
        }

    });
    return contextMenu;
};



/******************************************************************************
** This function creates the drawing manager
******************************************************************************/
function initDrawManager(){
	//log('drawingManager');
	var temp = new google.maps.drawing.DrawingManager({
		drawingMode: google.maps.drawing.OverlayType.NULL,
		drawingControl: false,
		polygonOptions: {
			fillColor: '#ff0000',
			fillOpacity: 0.50,
			strokeColor: '#ff0000',
			strokeOpacity: 0.75,
			strokeWeight: 5,
			clickable: true,
			zIndex: 1,
			editable: true
		},
		polylineOptions: {
			strokeColor: '#0000ff',
			strokeOpacity: 0.65,
			strokeWeight: 10,
			clickable: true,
			zIndex: 1,
			editable: true
		}
	});
	temp.setMap(map);
	return temp;
};



/******************************************************************************
** This function creates the masked area
******************************************************************************/
function maskInit(){
	var rects = new Array()
	var neastU = new google.maps.LatLng(84.574702, 177.539063);
	var swestU = new google.maps.LatLng(clat+mask2,-178.59375); //36.165324
	var upperB = new google.maps.LatLngBounds(swestU, neastU);
	var upperR = new google.maps.Rectangle({
		bounds: upperB,
		fillColor: '#aaaaaa',
		fillOpacity: 0.75,
		map: map,
		strokeWeight: 0.01,
		zIndex: 1
	});
	rects.push(upperR);

	var neastL = new google.maps.LatLng(clat+mask1, 178.59375); //36.163089
	var swestL = new google.maps.LatLng(-84.990100, -179.296875);
	var lowerB = new google.maps.LatLngBounds(swestL, neastL);
	var lowerR = new google.maps.Rectangle({
		bounds: lowerB,
		fillColor: '#aaaaaa',
		fillOpacity: 0.75,
		map: map,
		strokeWeight: 0.01,
		zIndex: 1
	});
	rects.push(lowerR);

	var neastE = new google.maps.LatLng(clat+mask1, 178.59375);
	var swestE = new google.maps.LatLng(clat+mask2, clng+mask4); //-86.781302
	var eastB = new google.maps.LatLngBounds(swestE, neastE);
	var eastR = new google.maps.Rectangle({
		bounds: eastB,
		fillColor: '#aaaaaa',
		fillOpacity: 0.75,
		map: map,
		strokeWeight: 0.01,
		zIndex: 1
	});
	rects.push(eastR);

	var neastW = new google.maps.LatLng(clat+mask1, clng+mask3); //-86.785636
	var swestW = new google.maps.LatLng(clat+mask2, -178.59375);
	var westB = new google.maps.LatLngBounds(swestW, neastW);
	var westR = new google.maps.Rectangle({
		bounds: westB,
		fillColor: '#aaaaaa',
		fillOpacity: 0.75,
		map: map,
		strokeWeight: 0.01,
		zIndex: 1
	});
	rects.push(westR);
	return rects;
}


