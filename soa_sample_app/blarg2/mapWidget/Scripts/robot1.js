// Constants
const TEAM_PROXIMITY_TO_FRIENDLY_ZONE_1 = 20;  // radius of inner ring in meters
const TEAM_PROXIMITY_TO_FRIENDLY_ZONE_2 = 30;  // radius of outer ring in meters
const DELTA_TEAM_PROXIMITY_TO_FRIENDLY_ZONE_1 = 30;
const DELTA_TEAM_PROXIMITY_TO_FRIENDLY_ZONE_2 = 30;
const DELTA_TEAM_PROXIMITY_TO_RISK = 60;  //30
const HOVER_RESIDUE_TO_NORMAL = 250;      // milliseconds
const HOVER_NORMAL_TO_DETAILED = 500;     // milliseconds
const HOVER_MOUSEOVER_TO_ORIGINAL = 500;  // milliseconds
const ROBOT_SPEED = 5.0; //3 super!
const ROBOT_NEGLECT_TIME = 1200;

const visual_state = {
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
        friendly_normal_to_detailed: 70
    }
};
const robot_type = {
    Base: 'Base',
    SUAV: 'UAV',
	HUAV: 'HUAV',
    Dismount: 'Dismount',
    Village: 'Village',
	NGO: 'NGO',
	Truck: 'Truck',
	Police: 'Police',
    Balloon: 'Balloon', 
    Invalid: 'Invalid',
    Avoid: 'Avoid',
    Home: 'Home',
    MaintainLocation: 'MaintainLocation',
    MoveToLocation: 'MoveToLocation',
    Refuel: 'Refuel',
    ReturnToFOB: 'ReturnToFOB'
};

/*******************************************************************************
 *  Helper Functions for the RVA
 *******************************************************************************/

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
            //log(robot.id + ' untoggled: at time ' + clock + ' ' + dist);
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
    
    if (robot.type == robot_type.Village) 
    {
        image_source = 'images/village.png';
    }
    else if(robot.type == robot_type.NGO)
    {
        image_source = 'images/ngo.png';
    }
    else if(robot.type == robot_type.Base)
    {
        image_source = 'images/fwd.png';
    }
    else if (robot.type === robot_type.SUAV)
    {
        image_source = 'images/small_uav.png';        
    }
    else if (robot.type == robot_type.HUAV)
    {
        image_source = 'images/heavy_uav.png';
    }
    else if (robot.type == robot_type.Balloon)
    {
        image_source = 'images/blimp_autonomous.png';
    }
    else if (robot.type == robot_type.Police)
    {
        //image_source = 'images/law_enforcement.png';
        image_source = 'images/truck_blue_mp.png';
    }
    else if (robot.type == robot_type.Truck)
    {
        //Blue, red, neutral?
        if (robot.affiliation === affiliation.RED)
        {
            image_source = 'images/truck_red_ter.png';
        }
        else if (robot.affiliation === affiliation.NEUTRAL)
        {
            image_source = 'images/truck_neutral_civ.png';
        }
        //else if (robot.affiliation === affiliation.UNCLASSIFIED)
        //{
        //    image_source = 'images/truck_unknown.png';
        //}
        else
        {
            image_source = 'images/truck_unknown.png';
        }
    }
    else if (robot.type == robot_type.Dismount)
    {
        //Blue, red, neutral?
        if (robot.affiliation === affiliation.RED)
        {
            image_source = 'images/dismount_red_ter.png';
        }
        else if (robot.affiliation === affiliation.NEUTRAL)
        {
            image_source = 'images/dismount_neutral.png';
        }
        //else if (robot.affiliation === affiliation.UNCLASSIFIED)
        //{
        //    image_source = 'images/truck_unknown.png';
        //}
        else
        {
            image_source = 'images/dismount_unknown.png';
        }
    }
    else if (robot.type ==robot_type.Avoid)
    {
        image_source = 'images/avoid.png';
    }
    else if (robot.type ==robot_type.Home)
    {
        image_source = 'images/home.png';
    }
    else if (robot.type ==robot_type.MaintainLocation)
    {
        image_source = 'images/maintainLocation.png';
    }
    else if (robot.type ==robot_type.MoveToLocation)
    {
        image_source = 'images/moveToLocation.png';
    }
    else if (robot.type ==robot_type.Refuel)
    {
        image_source = 'images/refuel.png';
    }
    else if (robot.type ==robot_type.ReturnToFOB)
    {
        image_source = 'images/returnToFOB.png';
    }
    else
        image_source = 'images/undefined.png';

    robot.image = new Image();
    robot.image.src = image_source;

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
    var status = robot.msg1;
    var task = msg2;
    var text_width = Math.max(context.measureText(status).width,
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
    // if (robot.affiliation === team_affiliation) {
    //     if (visual_score < visual_state.threshold.team_normal_to_detailed) {
            set_icon_normal(robot);
    //     } else {
    //         set_icon_detailed(robot);
    //     }
    // } else {
    //     if (visual_score < visual_state.threshold.friendly_residue_to_normal) {
    //         set_icon_residue(robot);
    //     } else if (visual_score < visual_state.threshold.friendly_normal_to_detailed) {
    //         set_icon_normal(robot);
    //     } else {
    //         set_icon_detailed(robot);
    //     }
    // }
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
        if (item.groupIcon > 0){
            set_icon_detailed(item);
        } 
    });
    
    item.addListener('toggle', function(status) {
        item.toggle = !item.toggle;
        if (status !== undefined) {
            item.status = status;
        }
        if (item.toggle) {
            set_visual_state(item, visual_state.score_range.max)
        } else {
            set_visual_state(item, item.visual_score);
        }
    });
    item.addListener('animationposition_changed', function() {
        var computeDistanceBetween = google.maps.geometry.spherical.computeDistanceBetween;
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

        // update visual scores of all nearby robots
   
    });
    return item;
};

var robot_count = 0;
function robot_options_template(map, position, affiliation, type, iid) {
    log(type);
    return {
        // Marker options
        map: map,
        position: position,
        visible: true,

        // SlidingMarker options
        easing: 'linear',
        duration: 100, // will be set by move_marker due to constant speed

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
        type: type,
        visual_score: 0,   
        groupIcon: -200         
    }
};
