function scenario_1() {
    var time;
    var trigger = google.maps.event.trigger;    

    time = 0;
    timed_log(time, 'Useful information will be shown in this information window. At the moment, you are EMS.\n');
    timed_log(time, 'At time t = ' + time/1000 + ' (seconds), a 911 call is made and a police task area is defined in blue.');
    timed_event(time, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16479537502464, -86.78436934947968), 
         new google.maps.LatLng(36.16530640992088, -86.78316235542297), 
         new google.maps.LatLng(36.16399416954029, -86.78229868412018), 
         new google.maps.LatLng(36.16347446430682, -86.78350567817688)], affiliation.POLICE)); });
    // timed_event(time, function() { trigger(map, 'add_item', robot, robot_options_template(map,
    //     new google.maps.LatLng(36.16530640992088, -86.78316235542297), robot_type.UAV, ROBOT_SPEED, affiliation.POLICE)); });
    // timed_event(time, function() { window.police_1 = last_item; });

    // time = 90;    // 9000
    // timed_log(time, 'At time t = ' + time/1000 + ', a police UAV starts patrolling the area.');
    // timed_event(time, function() { trigger(map, 'move_item', last_item, new google.maps.LatLng(36.16476072847041, -86.78381681442261)); });

    // time = 1400;   // 14000
    // timed_log(time, 'At time t = ' + time/1000 + ', the police UAV spots a suspicious object. ');
    // timed_event(time, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, 
    //     new google.maps.LatLng(36.16464812706336, -86.7839241027832), 'images/suspiciousitem.png', visual_state.residue_size, 20));});

    // time = 1800;   // 18000
    // timed_log(time, 'At time t = ' + time/1000 + ', Hazmat UGV\'s are brought in to identify the object. EMS UGV\'s are brought in to treat any potential patients. ');
    // timed_event(time, function() { trigger(map, 'add_item', robot, robot_options_template(map, 
    //     new google.maps.LatLng(36.16479278793637, -86.78436765513226), robot_type.UGV, ROBOT_SPEED, affiliation.HAZMAT)); });
    // timed_event(time, function() { window.hazmat_1 = last_item; });
    // timed_event(time, function() { trigger(map, 'move_item', hazmat_1, new google.maps.LatLng(36.16472175107858, -86.78406894207001)); });

    // time = 3000; // 30000
    // timed_event(time, function() { trigger(map, 'add_item', robot, robot_options_template(map, 
    //     new google.maps.LatLng(36.1640070920321, -86.78230723928164), robot_type.UGV, ROBOT_SPEED, affiliation.EMS));});
    // timed_event(time, function() {trigger(map, 'move_item', last_item, new google.maps.LatLng(36.16466978119268, -86.78381681442261));});

    // time = 3800; // 38000
    // timed_log(time, 'At time t = ' + time/1000 + ', EMS finds no imminent safety threats and leaves to patrol nearby areas.');
    // timed_event(time, function() {trigger(map, 'move_item', last_item, new google.maps.LatLng(36.1640070920321, -86.78230723928164)); });

    // time = 4000; // 40000
    // timed_log(time, 'At time t = ' + time/1000 + ', the police UAV has reached its neglect time limit.');
    // timed_event(time, function() { trigger(police_1, 'mouseover'); });

    // time = 4500; // 45000
    // timed_log(time, 'At time t = ' + time/1000 + ', the police UAV is given a new task.');
    // timed_event(time, function() { trigger(police_1, 'mouseout'); });
    // timed_event(time, function() {trigger(map, 'move_item', police_1, new google.maps.LatLng(36.164626472928084, -86.78284049034119));});

    // time = 5000; // 50000
    // timed_log(time, 'At time t = ' + time/1000 + ', a fault has occured on the hazmat UGV.');
    // timed_event(time, function() { trigger(hazmat_1, 'mouseover'); });

    // time = 5500; // 55000
    // timed_log(time, 'At time t = ' + time/1000 + ', the police UAV\'s icon  is forcefully brought forward by a friendly UVS.');
    // timed_event(time, function() { trigger(police_1, 'mouseover'); });
}
google.maps.event.addDomListener(window, 'load', scenario_1);   // Note: order of listeners may not be guaranteed