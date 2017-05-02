/*******************************************************************************
 *  Task area constants
 *******************************************************************************/

const STROKE_OPACITY = 0.45;  // standard stroke opacity
const FILL_OPACITY = 0.15;    // standard fill opacity

// Polygon task area constants
const hazmatTaskColor = '#FFFFDD'; // yellow
const emsTaskColor = '#FFFFFF';    // red
const policeTaskColor = '#DDDDFF'; // blue

/*******************************************************************************
 *  The task area and its options template
 *******************************************************************************/

function task_area(options) {
    var item = new google.maps.Polygon();
    item.setOptions(options);
    // DEBUG CONTEXT ONLY
    // if (DEBUG) {
    //     item.addListener('click', function(e) {
    //         log(e.latLng);
    //     });
    //}
    
    return item;
};

function task_area_options_template(map, paths, team_affiliation, color) {
    opacity_multiplier = 1;
    if (color === undefined) {
        // Set polygon color and opacity depending on the affiliation of the task
        if (team_affiliation === affiliation.EMS) {
            color = emsTaskColor;
            opacity_multiplier = 2;
        } else if (team_affiliation === affiliation.HAZMAT) {
            color = hazmatTaskColor;
        } else if (team_affiliation === affiliation.POLICE) {
            color = policeTaskColor;
        }
    };
    return {
        map: map,
        paths: paths,
        fillOpacity: FILL_OPACITY * opacity_multiplier,
        fillColor: color,
        strokeOpacity: STROKE_OPACITY * opacity_multiplier,
        strokeColor: color,
        visible: true,
        affiliation: affiliation,
        object_type: object_type.TASK_AREA
    }
};