//*****************************************************************************
//Functions triggered when the user right clicks on the map
//*****************************************************************************

goToLocation
Surveillance/search of an assigned area – either aerial or ground
Initial Detailed Victim Assessment – Ground Robots
Bomb Surveillance (includes 4 & 5)
Hazard Sampling (includes 6 & 7)
Gather  Samples
Guide Ambulatory Victims to Safety 
Gathering imagery 
Gross Victim Assessment 
Improved Communication
Place Robots in Safe Mode
Decontaminate self
case 'green_pGon':
                    drawingManager.setOptions({
                        polygonOptions: {
                            fillColor: '#348017',
                            fillOpacity: 0.30,
                            strokeColor: '#348017',
                            strokeOpacity: 0.75,
                            strokeWeight: 5,
                            clickable: false,
                            zIndex: 1,
                            editable: false
                        }
                    });
                    drawingManager.setDrawingMode(google.maps.drawing.OverlayType.POLYGON);
                    break;
                case 'red_pGon':
                    drawingManager.setOptions({
                        polygonOptions: {
                            fillColor: '#ff0000',
                            fillOpacity: 0.30,
                            strokeColor: '#ff0000',
                            strokeOpacity: 0.75,
                            strokeWeight: 5,
                            clickable: false,
                            zIndex: 1,
                            editable: false
                        }
                    });
                    drawingManager.setDrawingMode(google.maps.drawing.OverlayType.POLYGON);
                    break;
                case 'blue_pLine':
                    drawingManager.setOptions({
                        polylineOptions: {
                            strokeColor: '#2B60DE',
                            strokeOpacity: 0.85,
                            strokeWeight: 10,
                            clickable: true,
                            zIndex: 1,
                            editable: true
                        }
                    });
                    drawingManager.setDrawingMode(google.maps.drawing.OverlayType.POLYLINE);
                    break;
                case 'black_pLine':
                    drawingManager.setOptions({
                        polylineOptions: {
                            strokeColor: '#000000',
                            strokeOpacity: 0.85,
                            strokeWeight: 10,
                            clickable: true,
                            zIndex: 1,
                            editable: true
                        }
                    });