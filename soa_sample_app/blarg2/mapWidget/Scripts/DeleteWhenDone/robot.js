// Constants
const TEAM_PROXIMITY_TO_FRIENDLY_ZONE_1 = 20;  // radius of inner ring in meters
const TEAM_PROXIMITY_TO_FRIENDLY_ZONE_2 = 30;  // radius of outer ring in meters
const DELTA_TEAM_PROXIMITY_TO_FRIENDLY_ZONE_1 = 30;
const DELTA_TEAM_PROXIMITY_TO_FRIENDLY_ZONE_2 = 30;
const DELTA_TEAM_PROXIMITY_TO_RISK = 60;  //30
const HOVER_RESIDUE_TO_NORMAL = 250;      // milliseconds
const HOVER_NORMAL_TO_DETAILED = 500;     // milliseconds
const HOVER_MOUSEOVER_TO_ORIGINAL = 500;  // milliseconds
const ROBOT_SPEED = 0.005 / 3; //0.02
const ROBOT_NEGLECT_TIME = 1200;

const visual_state = {
    grouped_dim: 10,    // residue dimension in pixels
    residue_dim: 20,    // residue dimension in pixels
    normal_dim: 35,     // normal dimension in pixels
    detailed_dim: 50,   // detailed dimension in pixels
    score_range: {
        min: 0,
        max: 100    // range is inclusive
    },
    threshold: {
        team_normal_to_detailed: 60,
        friendly_residue_to_normal: 40,
        friendly_normal_to_detailed: 70,
    }
};


const robot_type = {
    surveillance: 'surveillance',
    hazardSampling: 'hazardSampling',
    searchArea: 'searchArea',
    gatherSamples: 'gatherSamples',
    goToX: 'goToX',
    victimSearch: 'victimSearch',
    victimAssessment: 'victimAssessment',
    guideVictims: 'guideVictims',
    UAV: 'UAV',
    UGV: 'UGV',
    responderUnknown: 'responderUnknown',
    responderTL1: 'responderTL1',
    responderTL2: 'responderTL2',
    responderTL3: 'responderTL3',
    responderTL4: 'responderTL4',
    responderTL5: 'responderTL5',
    responderTLUNonamb: 'responderTLUNonamb',
    responderTLUNonamb: 'responderTLUNonamb',
    responderTL1Nonamb: 'responderTL1Nonamb',
    responderTL2Nonamb: 'responderTL2Nonamb',
    responderTL3Nonamb: 'responderTL3Nonamb',
    responderTL4Nonamb: 'responderTL4Nonamb',
    responderTL5Nonamb: 'responderTL5Nonamb',
    responderTLUAmbUnknown: 'responderTLUAmbUnknown',
    responderTL1AmbUnknown: 'responderTL1AmbUnknown',
    responderTL2AmbUnknown: 'responderTL2AmbUnknown',
    responderTL3AmbUnknown: 'responderTL3AmbUnknown',
    responderTL4AmbUnknown: 'responderTL4AmbUnknown',
    responderTL5AmbUnknown: 'responderTL5AmbUnknown',
    victimUnknown: 'victimUnknown',
    victimTL1: 'victimTL1',
    victimTL2: 'victimTL2',
    victimTL3: 'victimTL3',
    victimTL4: 'victimTL4',
    victimTL5: 'victimTL5',
    victimTLUNonamb: 'victimTLUNonamb',
    victimTL1Nonamb: 'victimTL1Nonamb',
    victimTL2Nonamb: 'victimTL2Nonamb',
    victimTL3Nonamb: 'victimTL3Nonamb',
    victimTL4Nonamb: 'victimTL4Nonamb',
    victimTL5Nonamb: 'victimTL5Nonamb',
    victimTLUAmbUnknown: 'victimTLUAmbUnknown',
    victimTL1AmbUnknown: 'victimTL1AmbUnknown',
    victimTL2AmbUnknown: 'victimTL2AmbUnknown',
    victimTL3AmbUnknown: 'victimTL3AmbUnknown',
    victimTL4AmbUnknown: 'victimTL4AmbUnknown',
    victimTL5AmbUnknown: 'victimTL5AmbUnknown',
    suspiciousPersonGroup: 'suspiciousPersonGroup',
    HumanTypeVictimGroup: 'HumanTypeVictimGroup',
    egress: 'egress',
    ingressEgress: 'ingress-egress',
    ingress: 'ingress',
    nine11Call: 'nine11Call',
    eyeWitnessReport: 'eyeWitnessReport',
    suspiciousObject: 'suspiciousObject',
    bomb: 'bomb',
    gasHazardDivU: 'gasHazardDivU',
    gasHazardDivFlam: 'gasHazardDivFlam',
    gasHazardDivTox: 'gasHazardDivTox',
    gasHazardDivNonflamNontox: 'gasHazardDivNonflamNontox',
    gasHazardDivInvalid: 'gasHazardDivInvalid'
};

function ClickableOverlay(map, marker_position, x_offset, y_offset, width, height, robot) {
    this.map = map;
    this.marker_position = marker_position;
    this.x_offset = x_offset;
    this.y_offset = y_offset;
    this.width = width;
    this.height = height;
    this.robot = robot;
    this.canvas = null;    // will be set in onAdd
    this.setMap(map);
}

ClickableOverlay.prototype = new google.maps.OverlayView();

ClickableOverlay.prototype.onAdd = function() {
    // Create the canvas and set some basic attributes.
    var canvas = document.createElement('canvas');
    var robot = this.robot;
    canvas.width = this.width;
    canvas.height = this.height;
    canvas.style.position = 'absolute';
    canvas.addEventListener('click', function(e){
        var canvas_coord = canvas.getBoundingClientRect();
        var x_coord = e.clientX - canvas_coord.left;
        var y_coord = e.clientY - canvas_coord.top;
        // we expect the icon to be a square, so we can take radius as either w or h
        var radius = canvas.width / 2;
        var dist = Math.sqrt(Math.pow(x_coord - radius, 2) + Math.pow(y_coord - radius, 2));

        // log the distance from the center of the icon for Fitt's Law
        if (robot.toggle) {       
            google.maps.event.trigger(robot, 'toggle', 'Fault');
            robot.status = 'Good';
            //log('untoggle:' + robot.id + ' position:' + robot.position + ' time:' + clock + ' dist:' + dist);
        }
    });
    this.canvas = canvas;

    var panes = this.getPanes();
    panes.overlayMouseTarget.appendChild(canvas);
}
ClickableOverlay.prototype.draw = function() {
    var canvas = this.canvas;
    var context = canvas.getContext('2d');
    
    var overlayProjection = this.getProjection();
    var position = overlayProjection.fromLatLngToDivPixel(this.marker_position);
    var x_coord = position.x + this.x_offset;
    var y_coord = position.y + this.y_offset;
    canvas.style.left = x_coord + 'px';
    canvas.style.top = y_coord + 'px';

    if (DEBUG) {
        context.strokeRect(0, 0, canvas.width, canvas.height);
    }
}
ClickableOverlay.prototype.onRemove = function() {
    this.canvas.parentNode.removeChild(this.canvas);
    this.canvas = null;
}
ClickableOverlay.prototype.updatePosition = function(position) {
    // we need to check for the canvas to ensure that onAdd has been called
    if (this.canvas) {
        this.marker_position = position;
        var canvas = this.canvas;
        var overlayProjection = this.getProjection();
        var position = overlayProjection.fromLatLngToDivPixel(position);
        var x_coord = position.x + this.x_offset;
        var y_coord = position.y + this.y_offset;
        canvas.style.left = x_coord + 'px';
        canvas.style.top = y_coord + 'px';
    }
}


function set_image(robot) {
    var image_source;
    if(1 == 1){
        if (robot.rtype === robot_type.responderUnknown) { 
            image_source = 'images/respondertriagelevelunknown.png';
        } else if (robot.rtype === robot_type.responderTL1) { 
            image_source = 'images/respondertriagelevel1.png';
        } else if (robot.rtype === robot_type.responderTL2) { 
            image_source = 'images/respondertriagelevel2.png';
        } else if (robot.rtype === robot_type.responderTL3) { 
            image_source = 'images/respondertriagelevel3.png';
        } else if (robot.rtype === robot_type.responderTL4) { 
            image_source = 'images/respondertriagelevel4.png';
        } else if (robot.rtype === robot_type.responderTL5) { 
            image_source = 'images/respondertriagelevel5.png';
        } else if (robot.rtype === robot_type.responderTLUNonamb) { 
            image_source = 'images/respondertriagelevelunknownnonambulatory.png';
        } else if (robot.rtype === robot_type.responderTLUNonamb) { 
            image_source = 'images/respondertriagelevelunknownnonambulatory.png';
        } else if (robot.rtype === robot_type.responderTL1Nonamb) { 
            image_source = 'images/respondertriagelevel1nonambulatory.png';
        } else if (robot.rtype === robot_type.responderTL2Nonamb) { 
            image_source = 'images/respondertriagelevel2nonambulatory.png';
        } else if (robot.rtype === robot_type.responderTL3Nonamb) { 
            image_source = 'images/respondertriagelevel3nonambulatory.png';
        } else if (robot.rtype === robot_type.responderTL4Nonamb) { 
            image_source = 'images/respondertriagelevel4nonambulatory.png';
        } else if (robot.rtype === robot_type.responderTL5Nonamb) { 
            image_source = 'images/respondertriagelevel5nonambulatory.png';
        } else if (robot.rtype === robot_type.responderTLUAmbUnknown) { 
            image_source = 'images/respondertriagelevelunknownunknown.png';
        } else if (robot.rtype === robot_type.responderTL1AmbUnknown) { 
            image_source = 'images/respondertriagelevel1unknown.png';
        } else if (robot.rtype === robot_type.responderTL2AmbUnknown) { 
            image_source = 'images/respondertriagelevel2unknown.png';
        } else if (robot.rtype === robot_type.responderTL3AmbUnknown) { 
            image_source = 'images/respondertriagelevel3unknown.png';
        } else if (robot.rtype === robot_type.responderTL4AmbUnknown) { 
            image_source = 'images/respondertriagelevel4unknown.png';
        } else if (robot.rtype === robot_type.responderTL5AmbUnknown) { 
            image_source = 'images/respondertriagelevel5unknown.png';
        } else if (robot.rtype === robot_type.victimUnknown) { 
            image_source = 'images/victimtriagelevelunknown.png';
        } else if (robot.rtype === robot_type.victimTL1) { 
            image_source = 'images/victimtriagelevel1.png ';
        } else if (robot.rtype === robot_type.victimTL2) { 
            image_source = 'images/victimtriagelevel2.png ';
        } else if (robot.rtype === robot_type.victimTL3) { 
            image_source = 'images/victimtriagelevel3.png ';
        } else if (robot.rtype === robot_type.victimTL4) { 
            image_source = 'images/victimtriagelevel4.png ';
        } else if (robot.rtype === robot_type.victimTL5) { 
            image_source = 'images/victimtriagelevel5.png ';
        } else if (robot.rtype === robot_type.victimTLUNonamb) { 
            image_source = 'images/victimtriagelevelunknownnonambulatory.png';
        } else if (robot.rtype === robot_type.victimTL1Nonamb) { 
            image_source = 'images/victimtriagelevel1nonambulatory.png';
        } else if (robot.rtype === robot_type.victimTL2Nonamb) { 
            image_source = 'images/victimtriagelevel2nonambulatory.png';
        } else if (robot.rtype === robot_type.victimTL3Nonamb) { 
            image_source = 'images/victimtriagelevel3nonambulatory.png';
        } else if (robot.rtype === robot_type.victimTL4Nonamb) { 
            image_source = 'images/victimtriagelevel4nonambulatory.png';
        } else if (robot.rtype === robot_type.victimTL5Nonamb) { 
            image_source = 'images/victimtriagelevel5nonambulatory.png';
        } else if (robot.rtype === robot_type.victimTLUAmbUnknown) { 
            image_source = 'images/victimtriagelevelunknownunknown.png';
        } else if (robot.rtype === robot_type.victimTL1AmbUnknown) { 
            image_source = 'images/victimtriagelevel1unknown.png';
        } else if (robot.rtype === robot_type.victimTL2AmbUnknown) { 
            image_source = 'images/victimtriagelevel2unknown.png';
        } else if (robot.rtype === robot_type.victimTL3AmbUnknown) { 
            image_source = 'images/victimtriagelevel3unknown.png';
        } else if (robot.rtype === robot_type.victimTL4AmbUnknown) { 
            image_source = 'images/victimtriagelevel4unknown.png';
        } else if (robot.rtype === robot_type.victimTL5AmbUnknown) { 
            image_source = 'images/victimtriagelevel5unknown.png';
        } else if (robot.rtype === robot_type.suspiciousPersonGroup) { 
            image_source = 'images/suspiciousperson.png';
        } else if (robot.rtype === robot_type.HumanTypeVictimGroup) { 
            image_source = 'images/victimgroup.png';
        } else if (robot.rtype === robot_type.egress) { 
            image_source = 'images/egress.png ';
        } else if (robot.rtype === robot_type.ingressEgress) { 
            image_source = 'images/ingress-egress.png';
        } else if (robot.rtype === robot_type.ingress) { 
            image_source = 'images/ingress.png';
        } else if (robot.rtype === robot_type.nine11Call) { 
            image_source = 'images/a911call.png';
        } else if (robot.rtype === robot_type.eyeWitnessReport) { 
            image_source = 'images/eyewitnessreport.png ';
        } else if (robot.rtype === robot_type.suspiciousObject) { 
            image_source = 'images/suspiciousitem.png';
        } else if (robot.rtype === robot_type.bomb) { 
            image_source = 'images/bomb.png';
        } else if (robot.rtype === robot_type.gasHazardDivU) { 
            image_source = 'images/gas-unknown.png';
        } else if (robot.rtype === robot_type.gasHazardDivFlam) { 
            image_source = 'images/gas-flammable.png';
        } else if (robot.rtype === robot_type.gasHazardDivTox) { 
            image_source = 'images/gas-toxic.png';
        } else if (robot.rtype === robot_type.gasHazardDivNonflamNontox) { 
            image_source = 'images/gas-nonflammablenontoxic.png';
        } else if (robot.rtype === robot_type.gasHazardDivInvalid) { 
            image_source = 'images/gas-unknown.png';
        } else if (robot.rtype === robot_type.surveillance) {
            image_source = 'images/taskmainsymbol/surveillance.png';
        } else if (robot.rtype === robot_type.hazardSampling) { 
            image_source = 'images/taskmainsymbol/hazardsampling.png';
        } else if (robot.rtype === robot_type.searchArea) { 
            image_source = 'images/taskmainsymbol/searcharea.png';
        } else if (robot.rtype === robot_type.gatherSamples) { 
            image_source = 'images/taskmainsymbol/gathersamples.png';
        } else if (robot.rtype === robot_type.goToX) { 
            image_source = 'images/taskmainsymbol/gotox.png';
        } else if (robot.rtype === robot_type.victimSearch) { 
            image_source = 'images/taskmainsymbol/victimsearch.png';
        } else if (robot.rtype === robot_type.victimAssessment) { 
            image_source = 'images/taskmainsymbol/victimassessment.png';
        } else if (robot.rtype === robot_type.guideVictims) { 
            image_source = 'images/taskmainsymbol/guidevictims.png';
        } else if (robot.rtype === robot_type.UAV) {
            if (robot.affiliation === team_affiliation) {
                image_source = 'images/uav.png';
            } else {
                image_source = 'images/uav_friendly.png';
            }
        } else {
            if (robot.affiliation === team_affiliation) {
                image_source = 'images/ugv.png';
            } else {
                image_source = 'images/ugv_friendly.png';
            }
        }
       // log(robot.rtype);
        //log(image_source);
    }
    robot.image = new Image();
    robot.image.src = image_source;

    robot.grouped = new Image();
    robot.grouped.src = 'images/grouped.png';
};

function set_icon_grouped(robot) {
    if (robot.clickable_overlay) {
        robot.clickable_overlay.setMap(null);
        robot.clickable_overlay = null;
    }
    robot.setOpacity(1);
    robot.setIcon({
        url: robot.grouped.src,
        scaledSize: new google.maps.Size(visual_state.grouped_dim, visual_state.grouped_dim, 'px', 'px'),
    });
};

function set_icon_residue(robot) {
    if (robot.clickable_overlay) {
        robot.clickable_overlay.setMap(null);
        robot.clickable_overlay = null;
    }
    robot.setOpacity(0.5);
    robot.setIcon({
        url: robot.image.src,
        scaledSize: new google.maps.Size(visual_state.residue_dim, visual_state.residue_dim, 'px', 'px'),
    });
};

function set_icon_normal(robot) {
    if (robot.clickable_overlay) {
        robot.clickable_overlay.setMap(null);
        robot.clickable_overlay = null;
    }
    robot.setOpacity(1);
    robot.setIcon({
        url: robot.image.src,
        scaledSize: new google.maps.Size(visual_state.normal_dim, visual_state.normal_dim, 'px', 'px'),
    });
};

function set_icon_detailed(robot) {
    robot.setOpacity(1);

    // relative constants
    var canvas = robot.canvas;
    var context = robot.context;
    var icon_width = visual_state.detailed_dim;
    var icon_height = visual_state.detailed_dim;

    // Measure text to determine width of canvas
    var text_height = 10;
    context.font = text_height + 'px Arial';
    var flagTitle;
    if (robot.groupIcon == 1){
        flagTitle = [robot.rtype, 'Grouping'].join(' ');
    } else if (robot.groupIcon == 2){
        flagTitle = [robot.rtype, 'Task'].join(' ');
    } else {        
        flagTitle = robot.rtype;
    }
    var status = robot.msg1;
    var task = robot.msg2;
    var text_width = Math.max(context.measureText(flagTitle).width,
                              context.measureText(status).width,
                              context.measureText(task).width);
    var horizontal_padding = 7;   // number of pixels of horizontal padding on both sides of the text
    canvas.width = (text_width + icon_width / 2 + 2 * horizontal_padding) * 4 / 3;
    canvas.height = icon_height * 3 / 2;
    context.clearRect(0, 0, canvas.width, canvas.height);

    // Draw crosshair
    var offset = 15;    // pixel offset from bottom right of canvas
    var radius = 5;     // radius of the circle in pixels
    var crosshair_center_x = offset;
    var crosshair_center_y = canvas.height - offset;
    context.beginPath();
    context.arc(crosshair_center_x, crosshair_center_y, radius, 0, 2 * Math.PI);
    context.moveTo(crosshair_center_x - radius, crosshair_center_y);
    context.lineTo(crosshair_center_x + radius, crosshair_center_y);    // horizontal line
    context.moveTo(crosshair_center_x, crosshair_center_y - radius);
    context.lineTo(crosshair_center_x, crosshair_center_y + radius);    // vertical line
    context.stroke();

    var icon_center_x = canvas.width / 4;  // icon will be centered at 1/4 the width of the canvas

    // Draw lines to flag
    context.beginPath();
    context.moveTo(crosshair_center_x, crosshair_center_y - radius);
    context.lineTo(icon_center_x, 0);  // to top left of flag
    context.moveTo(crosshair_center_x, crosshair_center_y + radius);
    context.lineTo(icon_center_x, icon_height); // to bottom left of flag
    context.stroke();

    // Draw flag
    context.fillStyle = 'white';
    context.strokeStyle = 'black';
    context.fillRect(icon_center_x, 0, canvas.width - icon_center_x, icon_height);
    context.strokeRect(icon_center_x, 0, canvas.width - icon_center_x, icon_height);

    // Draw icon
    context.drawImage(robot.image, icon_center_x - icon_width / 2, 0, icon_width, icon_height);

    if (DEBUG) {
        context.strokeRect(0, 0, canvas.width, canvas.height);
    }

    // Draw Text
    var vertical_padding = (icon_height - 3 * text_height) / 5;
    context.fillStyle = 'black';
    context.fillText(flagTitle, icon_center_x + icon_width / 2 + horizontal_padding, vertical_padding + text_height);
    context.fillText(status, icon_center_x + icon_width / 2 + horizontal_padding, 2 * (vertical_padding + text_height));
    context.fillText(task, icon_center_x + icon_width / 2 + horizontal_padding, 3 * (vertical_padding + text_height));

    robot.setIcon({
        url: canvas.toDataURL(),
        anchor: new google.maps.Point(offset, canvas.height - offset)
    });

    // Add clickable overlay for Fitt's Law
    if (!robot.clickable_overlay) {
        robot.clickable_overlay = new ClickableOverlay(map, robot.position, 
            icon_center_x - icon_width / 2 - offset, -canvas.height + offset, icon_width, icon_height, robot);
    } // Better way might just be to setMap, but regenerating ClickableOverlay is faster for now.
};

function set_visual_state(robot, visual_score) {
    if (robot.affiliation === team_affiliation) {
        if (visual_score < visual_state.threshold.team_normal_to_detailed) {
            set_icon_normal(robot);
        } else {
            set_icon_detailed(robot);
        }
    } else {
        if (visual_score < visual_state.threshold.friendly_residue_to_normal) {
            set_icon_residue(robot);
        } else if (visual_score < visual_state.threshold.friendly_normal_to_detailed) {
            set_icon_normal(robot);
        } else {
            set_icon_detailed(robot);
        }
    }
};

function set_visual_state2(tItem, state) {
    //log("set_visual_state2");
    if (state == 'normal') {
            set_icon_normal(tItem);
    } else if (state == 'details') {
            set_icon_detailed(tItem);
    } else if (state == 'residue') {
            set_icon_residue(tItem);
    } else if (state == 'grouped') {
        set_icon_grouped(tItem);
    }
};

/*******************************************************************************
 *  The robot and its options template
 *******************************************************************************/
var animateTo;
function robot(options) {
    //log(options);
    var item = new google.maps.Marker();
    item.setOptions(options);
    set_image(item);
    item.canvas = document.createElement('canvas');
    item.context = item.canvas.getContext('2d');
    set_visual_state2(item, 'normal');

    item.animateFunctionAdapter = function (marker, destPosition, easing, duration) {
        if (!animateTo) {
            animateTo = google.maps.Marker.prototype.animateTo;
            if (!animateTo) {
                throw new Error("Please either reference markerAnimate.js, or provide an alternative animateFunctionAdapter");
            }
        }
        animateTo.call(marker, destPosition, {
            easing: easing,
            duration: duration,
            complete: function () {
                google.maps.event.trigger(item, 'execute_event');
                if(item.rtype === robot_type.UAV || item.rtype === robot_type.UGV) {
                    var cmd = "moveDone," + item.id.toString();
                    log(cmd);
                    webView.interactionFromJS(cmd);
                }
            }
        });
    },

    // Events
    item.addListener('push_event', function(fn) {
        item.event_queue.push(fn);
    });

    item.addListener('execute_event', function() {
        if (item.event_queue.length !== 0) {
            var fn = item.event_queue.shift();
            fn();
        };
    });

    // Listeners
    item.addListener('change_visual_score', function(delta) {
        var new_visual_score = item.visual_score + delta;
        if (new_visual_score + delta < visual_state.score_range.min) { 
            item.visual_score = visual_state.score_range.min;
        } else if (new_visual_score > visual_state.score_range.max) {
            item.visual_score = visual_state.score_range.max;
        } else {
            item.visual_score = new_visual_score;
        }
        if (!item.toggle) {
            set_visual_state(item, item.visual_score);
        }
    });

    item.addListener('mouseover', function() {
        //log(item.groupIcon);
        //log("mousover " + item.id);
        webView.fromJS(item.groupIcon);
        if (item.groupIcon > 0){
            set_icon_detailed(item);
        } else {
            sendMouseOver(item.id);        
        }   
    });

    item.addListener('mouseout', function() {
        sendMouseOut(item);
    });

    item.addListener('click', function() {
        //log('clicked');
        sendClick(item.id);
    });

    item.addListener('toggle', function(status) {
        if (status !== undefined) {
            item.status = status;
        }
    });  

     item.addListener('animationposition_changed', function() {
        var computeDistanceBetween = google.maps.geometry.spherical.computeDistanceBetween;
        var trigger = google.maps.event.trigger;
        // Sliding Marker sets position once at the beginning of setPosition().
        if (computeDistanceBetween(item.previous_position, item.position) <=
            computeDistanceBetween(item.previous_position, item.getAnimationPosition())) {
            item.previous_position = item.position;
        };

        item.position = item.getAnimationPosition();

        // update overlay position
        if (item.clickable_overlay) {
            item.clickable_overlay.updatePosition(item.position);
        }   
    });
     //log("before robot return groupIcon Value: " + item.groupIcon);
    return item;
};


var robot_count = 0;
function robot_options_template(map, position, affiliation, rype, iid) {
    return {
        // Marker options
        map: map,
        position: position,
        visible: true,

        // SlidingMarker options
        easing: 'linear',
        duration: 1000, // will be set by move_marker due to constant speed

        // RVA options
        affiliation: affiliation,
        event_queue: [],
        toggle: false,
        clickable_overlay: null,    // will be set by set_icon_detailed
        id: iid, //++robot_count,
        image: null,    // will be set by set_image        
        neglect_time: ROBOT_NEGLECT_TIME,        
        object_type: object_type.ROBOT,
        previous_position: position,    // used for calculating direction
        speed: ROBOT_SPEED,
        msg1: 'Good',
        msg2: 'None',
        rtype: rype,
        visual_score: 0,
        groupIcon: -200     
    }
};