

function scenario_0() {
    var time;
    var trigger = google.maps.event.trigger;
    var LatLng = google.maps.LatLng;

    time = 0;
    timed_event(time, function() { 
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16494911892434, -86.78364783525467), affiliation.EMS, robot_type.UAV)); 
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16482569074705, -86.78357005119324), affiliation.HAZMAT, robot_type.UAV));
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16468493907962, -86.78346812725067), affiliation.EMS, robot_type.UGV)); 
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.1645918262992, -86.78341716527939), affiliation.POLICE, robot_type.UGV));
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16447272839556, -86.78333133459091), 'images/classifyobjectuncertainsuspiciousitem.png', 20));
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16461348044404, -86.7831489443779), 'images/suspiciousitem.png', 20));
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16468493907962, -86.78296118974686), 'images/bomb.png', 40));
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16474123977691, -86.78279221057892), 'images/victimtriagelevelunknownunknown.png', 0)); 
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16483651778792, -86.78262859582901), 'images/HAZMATReading.png', 0)); 

        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16432331440603, -86.78321868181229), 'images/HAZMATReadingRes.png', 0));
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16416740385243, -86.78314089775085), 'images/victimtriagelevelunknownunknownRes.png', 0)); 
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16396818436045, -86.78297996520996), 'images/grouped.png', 0)); 
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164027429204516, -86.78302019834518), 'images/grouped.png', 0)); 
        
        // trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164027429204516, -86.78302019834518), 'images/victimtriagelevel1unknownRes.png', 0)); 


        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16408582813322, -86.7830041050911), 
             new google.maps.LatLng(36.16402736153483, -86.7830953001976), 
             new google.maps.LatLng(36.16395590229978, -86.78301483392715), 
             new google.maps.LatLng(36.16397755662032, -86.7829155921936)], null, '#663300'));

        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.165046562084896, -86.78359150886536), 
             new google.maps.LatLng(36.165200305491915, -86.78323209285736), 
             new google.maps.LatLng(36.16481269829603, -86.78297191858292), 
             new google.maps.LatLng(36.16465462330279, -86.7833662033081)], affiliation.POLICE));
        window.g1 = last_item;
    });


    // timed_event(time, function() { window.ems_1 = last_item; });

    // timed_event(time, function() { trigger(map, 'move_item', last_item, new LatLng(36.164734743544685, -86.78440153598785)); });
    // timed_event(time, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16526310200803, -86.78319454193115)); });
    // timed_event(time, function() { trigger(last_item, 'push_event', function() {
    //     timed_event(500, function() {trigger(map, 'move_item', last_item, new LatLng(36.16526310200803, -86.78319454193115)); }); });
    // });

    // timed_event(time, function() { trigger(last_item, 'push_event', function() { 
    //     trigger(map, 'move_item', last_item, new LatLng(36.16526310200803, -86.78319454193115)); }); 
    // });

    time = 10000;
    // timed_event(time, function() { swap_icon(g1, 'images/victimtriagelevel1unknownRes.png'); });
    timed_event(time, function() { swap_color(g1, 'yellow'); });
    // timed_event(time, function() { trigger(last_item, 'toggle', 'Fault') });

}
google.maps.event.addDomListener(window, 'load', scenario_0);   // Note: order of listeners may not be guaranteed









