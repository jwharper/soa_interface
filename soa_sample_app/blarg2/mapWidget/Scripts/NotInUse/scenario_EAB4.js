function scenario_2() {
    var time;

    var coefficient = 1;
    // ROBOT_SPEED /= 3;


    time = 0
    timed_event(time, function() { 
        add_robot(36.163917296691636, -86.78233623504638, affiliation.POLICE, robot_type.UAV);  window.police_1 = last_item;
        add_robot(36.163975763372136, -86.78239792585373, affiliation.POLICE, robot_type.UAV);  window.police_2 = last_item;
        add_robot(36.16400607941151, -86.782365739345555, affiliation.POLICE, robot_type.UAV);  window.police_3 = last_item;
        add_robot(36.16394328188834, -86.78228259086609, affiliation.POLICE, robot_type.UAV);   window.police_4 = last_item;
        add_robot(36.16477588633977, -86.78456246852875, affiliation.HAZMAT, robot_type.UAV);   window.hazmat_1 = last_item;
        add_robot(36.16473041272289, -86.78447127342224, affiliation.HAZMAT, robot_type.UAV);   window.hazmat_2 = last_item;
        add_robot(36.16482785615534, -86.78445786237716, affiliation.HAZMAT, robot_type.UGV);   window.hazmat_3 = last_item;
        add_robot(36.164784547978094, -86.78441762924194, affiliation.HAZMAT, robot_type.UGV);  window.hazmat_4 = last_item;
        add_robot(36.16487332971568, -86.78437739610672, affiliation.HAZMAT, robot_type.UGV);   window.hazmat_5 = last_item;
        add_robot(36.16480911980213, -86.78433688295547, affiliation.HAZMAT, robot_type.UGV);   window.hazmat_6 = last_item;
        add_robot(36.16539519106742, -86.78292632102966, affiliation.EMS, robot_type.UAV);      window.ems_1 = last_item;
        add_robot(36.1654861375035, -86.78298532962799, affiliation.EMS, robot_type.UAV);       window.ems_2 = last_item;
        add_robot(36.16544282968993, -86.78305774927139, affiliation.EMS, robot_type.UGV);      window.ems_3 = last_item;
        add_robot(36.165354048597365, -86.78301483392715, affiliation.EMS, robot_type.UGV);     window.ems_4 = last_item;
        add_robot(36.165393025674774, -86.78318649530411, affiliation.EMS, robot_type.UGV);     window.ems_5 = last_item;
        add_robot(36.1653042445258, -86.78309798240661, affiliation.EMS, robot_type.UGV);       window.ems_6 = last_item;
    });

    //******** Replace time value   
    time = 1400;
    timed_event(time, function() { 
        //top left
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16457640853847, -86.78324818611145), 
             new google.maps.LatLng(36.16407619603713, -86.78464829921722), 
             new google.maps.LatLng(36.16503330982449, -86.78550124168396), 
             new google.maps.LatLng(36.165522689281815, -86.78413063287735)], affiliation.POLICE));
        window.policeTask1 = last_item;
        police_4.task = 'Search';

        //top right
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16461971683485, -86.7832025885582), 
             new google.maps.LatLng(36.16532130783554, -86.78155303001404),  
             new google.maps.LatLng(36.16612466513974, -86.7821940779686),
             new google.maps.LatLng(36.165628793270265, -86.78394019603729)], affiliation.POLICE));
        window.policeTask2 = last_item;
        police_1.task = 'Search';

        //bottom right
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16520437644026, -86.78155303001404), 
             new google.maps.LatLng(36.16461105519069, -86.78317844867706),
             new google.maps.LatLng(36.16353483691889, -86.78231745958328),  
             new google.maps.LatLng(36.164039383743265, -86.78077518939972)], affiliation.POLICE));
        window.policeTask3 = last_item;
        police_2.task = 'Search';

        //bottom left
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16459589728945, -86.78322404623031), 
             new google.maps.LatLng(36.16395709735834, -86.78464025259018), 
             new google.maps.LatLng(36.16282673353819, -86.78402870893478), 
             new google.maps.LatLng(36.16330096861985, -86.78251057863235)], affiliation.POLICE));
        window.policeTask4 = last_item;
        police_3.task = 'Search';
    });


    //******** Replace time value
    time = 5595;
    //Charlotte Avenue
    timed_event(time, function() { 
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16494885907391, -86.78434520959854), 
             new google.maps.LatLng(36.16478645353657, -86.78422719240188), 
             new google.maps.LatLng(36.16521736882428, -86.78320527076721), 
             new google.maps.LatLng(36.16536678110966, -86.78335815668106)], affiliation.HAZMAT));
        window.hazmatTask1 = last_item;
        hazmat_5.task = 'Gather Samples';
        hazmat_6.task = 'Gather Samples'; 
    });


    //******** Replace time value
    time = 77580;
    //6th Avenue North
    timed_event(time, function() { 
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16536894649887, -86.78328305482864), 
             new google.maps.LatLng(36.16544040444572, -86.78310871124267), 
             new google.maps.LatLng(36.164379355506654, -86.78248107433319), 
             new google.maps.LatLng(36.16432955081577, -86.7826098203659)], affiliation.HAZMAT));
        window.hazmatTask2 = last_item;
        hazmat_4.task = 'Gather Samples';
        hazmat_3.task = 'Gather Samples'; 
    });


    //******** Replace time value
    time = 137000;
    timed_event(time, function() { trigger(map, 'delete_item', hazmatTask2); });


    //******** Replace time value
    time = 429810;

    timed_event(time, function() { trigger(map, 'delete_item', hazmatTask1); });

    //******** Replace time value
    time = 17370;
    //Search for victims
    timed_event(time, function() { 
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.16485141579189, -86.78380340337753), 
             new google.maps.LatLng(36.16517839165954, -86.78325086832046), 
             new google.maps.LatLng(36.16402855657988, -86.78251057863235),
             new google.maps.LatLng(36.163610627409284, -86.78348422050476),
             new google.maps.LatLng(36.1638055169371, -86.78360491991043), 
             new google.maps.LatLng(36.164002571411444, -86.7831489443779)], affiliation.EMS)); 
        window.emsTask1 = last_item;    //(36.164032887440456, -86.78245157003402)
        //timed_event(time, function() { trigger(map, 'delete_item', hazmatTask1); });
        ems_1.task = 'Victim Search'; 
    });


    //******** Replace time value
    time = 38620;
    //Triage Victims 1
    timed_event(time, function() { 
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.1650376406213, -86.7833286523819), 
             new google.maps.LatLng(36.1648752352679, -86.78372025489807), 
             new google.maps.LatLng(36.164706333343396, -86.78359150886535),
             new google.maps.LatLng(36.16484491956465, -86.78319990634918)], affiliation.EMS));
        window.emsTask2 = last_item;
        ems_3.task = 'Triage Victims';
        ems_4.task = 'Triage Victims';
        ems_5.task = 'Triage Victims';
        ems_6.task = 'Triage Victims'; 
    });


    //******** Replace time value
    time = 59397;
    timed_event(time, function() { trigger(map, 'delete_item', emsTask2); });


    //******** Replace time value
    //time = 22620;
    //Triage Victims 2
    timed_event(time, function() { 
        trigger(map, 'add_item', task_area, task_area_options_template(map,
            [new google.maps.LatLng(36.1650376406213, -86.7833286523819), 
             new google.maps.LatLng(36.1648752352679, -86.78372025489807), 
             new google.maps.LatLng(36.16409351945917, -86.78319454193115),
             new google.maps.LatLng(36.16425592643219, -86.7828243970871)], affiliation.EMS));
        window.emsTask3 = last_item; 
    });


    //******** Replace time value
    time = 2000;
    timed_event(time, function() { 
        trigger(map, 'move_item', police_1, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_2, new LatLng(36.1646437962368, -86.78313553333282)); 
        trigger(map, 'move_item', police_3, new LatLng(36.1646437962368, -86.78313553333282)); 
        trigger(map, 'move_item', police_4, new LatLng(36.1646437962368, -86.78313553333282)); 
    });

    //******** Replace time value
    // time = 4000;
    //     //Police UAVs fly around
    //     timed_event(time, function() { police_1.speed /= 3; });
    //     timed_event(time, function() { police_2.speed /= 3; });
    //     timed_event(time, function() { police_3.speed /= 3; });
    //     timed_event(time, function() { police_4.speed /= 3; });

    timed_event(time, function() { trigger(last_item, 'toggle', 'Fault') });

    //*******************************************************************************************************************
    //*******************************************************************************************************************
    //Begin pasting in directly from excel; after pasting, replace double ampersands with a return
    //*******************************************************************************************************************
    //*******************************************************************************************************************

timed_event(21000, function() { setProbe("False outteam proximity; ask user if if any of their robots are near other team's robots"); });
timed_event(42000, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
timed_event(65000, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
timed_event(84000, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
timed_event(105000, function() { setProbe("False neglect/fault event; ask user if if any of their robots require attention"); });
timed_event(130000, function() { setProbe("Fault event; prompt if user fails to click"); });
timed_event(156000, function() { setProbe("Ask user if any of their robots are near high risk item"); });
timed_event(175000, function() { setProbe("Neglect event; prompt if user fails to click"); });
timed_event(199000, function() { setProbe("Ask user if any of their robots are near high risk item"); });
timed_event(220000, function() { setProbe("Neglect event; prompt if user fails to click"); });
timed_event(246000, function() { setProbe("Ask user if any of their robots are near high risk item"); });
timed_event(267000, function() { setProbe("False neglect/fault event; ask user if if any of their robots require attention"); });
timed_event(288000, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
timed_event(308000, function() { setProbe("Fault event; prompt if user fails to click"); });
timed_event(328000, function() { setProbe("False outteam proximity; ask user if if any of their robots are near other team's robots"); });
timed_event(348000, function() { setProbe("Fault event; prompt if user fails to click"); });
timed_event(367000, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
timed_event(380000, function() { setProbe("Neglect event; prompt if user fails to click"); });
timed_event(400000, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
timed_event(415000, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });


timed_event(13000, function() { trigger(last_item, 'toggle', 'Fault') });
timed_event(28000, function() { trigger(last_item, 'toggle', 'Fault') });
timed_event(328000, function() { trigger(last_item, 'toggle', 'Fault') });
timed_event(175000, function() { trigger(last_item, 'toggle', 'Requires operator input') });
timed_event(220000, function() { trigger(last_item, 'toggle', 'Requires operator input') });
timed_event(380000, function() { trigger(last_item, 'toggle', 'Requires operator input') });






    timed_event(time, function() { 
        trigger(map, 'move_item', police_1, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_2, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_3, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_4, new LatLng(36.1646437962368, -86.78313553333282)); 
    });

    // tr
    timed_event(time, function() { 
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165315071500586, -86.78171932697296)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.164856006457725, -86.78322941064835)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165507791401275, -86.78190171718597)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16499675781797, -86.78330987691879)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165715668515794, -86.78204119205475)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16515890308227, -86.78356468677521)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16585399311749, -86.78214848041534)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16533430021465, -86.7837256193161)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16604238094385, -86.78223967552185)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16557032783512, -86.78387850522995)); }); });
        trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16530831547907, -86.78316235542297)); }); }); 

        //br
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16458749546951, -86.78310066461563)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16502707346249, -86.78156107664108)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16434280320342, -86.78293436765671)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16484734482729, -86.78143233060837)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16416307299929, -86.78280293941498)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16454418715945, -86.78123384714127)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16389646522996, -86.78259640932083)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.164375024681725, -86.78110241889953)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16365826712878, -86.78243279457092)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16419962540282, -86.78097367286682)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.1635001898075, -86.78236037492752)); }); });
        trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16399607513039, -86.78230673074722)); }); });
        //bl
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16452469841214, -86.78325891494751)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163842589203114, -86.78448736667633)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.164236697470095, -86.78308725357056)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16358273651459, -86.78439617156982)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.164054801593096, -86.78294777870178)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163353199256576, -86.78424060344696)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163859652843435, -86.78299069404602)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16317320693955, -86.7841386795044)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163593303884646, -86.78291022777557)); }); }); 
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16297398492088, -86.78410917520523)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16331829222148, -86.7826983332634)); }); });
        trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163491528027265, -86.78351372480392)); }); });
        //tl
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16458316463957, -86.78329110145569)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16410677188674, -86.78464829921722)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.164743405187544, -86.7834198474884)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16425402086494, -86.78476095199585)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16487766052959, -86.78350567817688)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16444457795554, -86.78488433361053)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16501382119878, -86.78378731012344)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.1645937318665, -86.78497821092605)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16525851137018, -86.7839053273201)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.164851415796036, -86.78524106740951)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.165429577496525, -86.78402066230774)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16500082877895, -86.78536981344223)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.165498869998416, -86.78416281938553)); }); });
        trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16479078435941, -86.78435325622558)); }); });
    });

//create normal victim
timed_event(33000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16499242701067,  -86.78335279226303), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(33002, function() { window.ems4 = last_item; });
timed_event(36000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164940457304226,  -86.78347617387771), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(36002, function() { window.ems3 = last_item; });
timed_event(42000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1648754951227,  -86.78355664014816), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(42002, function() { window.ems2 = last_item; });
timed_event(45000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164871164308664,  -86.78363710641861), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(45002, function() { window.ems1 = last_item; });
timed_event(69000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16476289388051,  -86.78346008062362), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(69002, function() { window.ems6 = last_item; });
timed_event(72000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16474557059812,  -86.78356200456619), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(72002, function() { window.ems5 = last_item; });
timed_event(81000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164674112017835,  -86.78346276283264), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(81002, function() { window.ems7 = last_item; });
timed_event(99000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164604818786834,  -86.78337961435318), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(99002, function() { window.ems8 = last_item; });
timed_event(114000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16462647292811,  -86.78330719470978), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(114002, function() { window.ems9 = last_item; });
timed_event(117000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16464596165013,  -86.78321063518524), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(117002, function() { window.ems10 = last_item; });
timed_event(135000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644575704676,  -86.78339302539825), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(135002, function() { window.ems13 = last_item; });
timed_event(138000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16445323963048,  -86.7835083603859), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(138002, function() { window.ems12 = last_item; });
timed_event(147000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164539856327146,  -86.783167719841), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(147002, function() { window.ems11 = last_item; });
timed_event(159000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644640667228,  -86.78324550390243), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(159002, function() { window.ems14 = last_item; });
timed_event(162000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16438611162475,  -86.78330987691879), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(162002, function() { window.ems15 = last_item; });
timed_event(162015, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16436662283812,  -86.7832562327385), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(162017, function() { window.ems16 = last_item; });
timed_event(177000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16429083306628,  -86.78318113088608), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(177002, function() { window.ems17 = last_item; });
timed_event(192000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16421287779595,  -86.78319722414017), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(192002, function() { window.ems19 = last_item; });
timed_event(204000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164195554392016,  -86.78305774927139), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(204002, function() { window.ems20 = last_item; });
timed_event(210000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16435796115361,  -86.78290218114853), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(210002, function() { window.ems18 = last_item; });
timed_event(210015, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164267013408576,  -86.78286999464035), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(210017, function() { window.ems21 = last_item; });
timed_event(225000, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16404180901432,  -86.78310066461563), 'images/victimtriagelevelunknownunknown.png', 0)); });
timed_event(225002, function() { window.ems22 = last_item; });

//create residue victim
timed_event(48020, function() { swap_icon(ems4, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(51020, function() { swap_icon(ems3, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(57020, function() { swap_icon(ems2, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(60020, function() { swap_icon(ems1, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(84020, function() { swap_icon(ems6, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(87020, function() { swap_icon(ems5, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(96020, function() { swap_icon(ems7, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(114020, function() { swap_icon(ems8, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(129020, function() { swap_icon(ems9, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(132020, function() { swap_icon(ems10, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(150020, function() { swap_icon(ems13, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(153020, function() { swap_icon(ems12, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(162020, function() { swap_icon(ems11, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(174020, function() { swap_icon(ems14, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(177020, function() { swap_icon(ems15, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(177035, function() { swap_icon(ems16, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(192020, function() { swap_icon(ems17, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(219020, function() { swap_icon(ems20, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(225020, function() { swap_icon(ems18, 'images/victimtriagelevelunknownunknownRes.png');});
timed_event(225035, function() { swap_icon(ems21, 'images/victimtriagelevelunknownunknownRes.png');});

//create grouped victim
timed_event(137045, function() { swap_icon(ems6, 'images/grouped.png');});
timed_event(137050, function() { swap_icon(ems5, 'images/grouped.png');});
timed_event(137055, function() { swap_icon(ems7, 'images/grouped.png');});
timed_event(137060, function() { swap_icon(ems8, 'images/grouped.png');});
timed_event(137065, function() { swap_icon(ems9, 'images/grouped.png');});
timed_event(137070, function() { swap_icon(ems10, 'images/grouped.png');});
timed_event(179030, function() { swap_icon(ems12, 'images/grouped.png');});
timed_event(179035, function() { swap_icon(ems11, 'images/grouped.png');});
timed_event(179040, function() { swap_icon(ems14, 'images/grouped.png');});
timed_event(179045, function() { swap_icon(ems15, 'images/grouped.png');});
timed_event(179050, function() { swap_icon(ems16, 'images/grouped.png');});
timed_event(245025, function() { swap_icon(ems17, 'images/grouped.png');});
timed_event(245035, function() { swap_icon(ems20, 'images/grouped.png');});
timed_event(245045, function() { swap_icon(ems21, 'images/grouped.png');});

//Create grouped victim areas
 timed_event(137027, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.16489498378279,  -86.78373098373413),
                 new google.maps.LatLng(36.165050892889234,  -86.7833286523819),
                 new google.maps.LatLng(36.16466111954168,  -86.78311944007873),
                 new google.maps.LatLng(36.16456151048634,  -86.78350299596786)], null, '#663300')); });  
timed_event(137028, function() { window.emsGroup1 = last_item; });
 timed_event(179027, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.16450087882547,  -86.78357273340225),
                 new google.maps.LatLng(36.164604818786834,  -86.78311675786972),
                 new google.maps.LatLng(36.16438611162472,  -86.78318113088608) ,
                 new google.maps.LatLng(36.164329810672356,  -86.78332597017288)], null, '#663300')); });  
timed_event(179028, function() { window.emsGroup2 = last_item; });
 timed_event(245027, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.164318983561515, -86.78330451250076),
                 new google.maps.LatLng(36.16444024711771,  -86.78283244371414),
                 new google.maps.LatLng(36.164275675103106,  -86.78278148174286),
                 new google.maps.LatLng(36.163961688064155,  -86.78314357995987)], null, '#663300')); });  
timed_event(245028, function() { window.emsGroup3 = last_item; });

//create normal triaged
//create normal triaged
timed_event(101599, function() { swap_icon(ems4, 'images/victimtriagelevel1unknown.png');});
timed_event(99424, function() { swap_icon(ems3, 'images/victimtriagelevel1unknown.png');});
timed_event(100333, function() { swap_icon(ems2, 'images/victimtriagelevel1unknown.png');});
timed_event(102520, function() { swap_icon(ems1, 'images/victimtriagelevel1unknown.png');});
timed_event(144772, function() { swap_icon(ems6, 'images/victimtriagelevel1unknown.png');});
timed_event(137410, function() { swap_icon(ems5, 'images/victimtriagelevel1unknown.png');});
timed_event(138664, function() { swap_icon(ems7, 'images/victimtriagelevel1unknown.png');});
timed_event(146413, function() { swap_icon(ems8, 'images/victimtriagelevel1unknown.png');});
timed_event(182602, function() { swap_icon(ems9, 'images/victimtriagelevel1unknown.png');});
timed_event(181303, function() { swap_icon(ems10, 'images/victimtriagelevel1unknown.png');});
timed_event(177196, function() { swap_icon(ems13, 'images/victimtriagelevel1unknown.png');});
timed_event(183871, function() { swap_icon(ems12, 'images/victimtriagelevel1unknown.png');});
timed_event(218758, function() { swap_icon(ems11, 'images/victimtriagelevel1unknown.png');});
timed_event(188248, function() { swap_icon(ems14, 'images/victimtriagelevel1unknown.png');});
timed_event(211306, function() { swap_icon(ems15, 'images/victimtriagelevel1unknown.png');});
timed_event(223867, function() { swap_icon(ems16, 'images/victimtriagelevel1unknown.png');});
timed_event(290182, function() { swap_icon(ems17, 'images/victimtriagelevel1unknown.png');});
timed_event(197839, function() { swap_icon(ems19, 'images/victimtriagelevel1unknown.png');});
timed_event(241306, function() { swap_icon(ems20, 'images/victimtriagelevel1unknown.png');});
timed_event(235678, function() { swap_icon(ems18, 'images/victimtriagelevel1unknown.png');});
timed_event(355690, function() { swap_icon(ems21, 'images/victimtriagelevel1unknown.png');});
timed_event(227839, function() { swap_icon(ems22, 'images/victimtriagelevel1unknown.png');});

//create residue triaged
timed_event(106599, function() { swap_icon(ems4, 'images/victimtriagelevel1unknownRes.png');});
timed_event(104424, function() { swap_icon(ems3, 'images/victimtriagelevel1unknownRes.png');});
timed_event(105333, function() { swap_icon(ems2, 'images/victimtriagelevel1unknownRes.png');});
timed_event(107520, function() { swap_icon(ems1, 'images/victimtriagelevel1unknownRes.png');});
timed_event(149772, function() { swap_icon(ems6, 'images/victimtriagelevel1unknownRes.png');});
timed_event(142410, function() { swap_icon(ems5, 'images/victimtriagelevel1unknownRes.png');});
timed_event(143664, function() { swap_icon(ems7, 'images/victimtriagelevel1unknownRes.png');});
timed_event(151413, function() { swap_icon(ems8, 'images/victimtriagelevel1unknownRes.png');});
timed_event(187602, function() { swap_icon(ems9, 'images/victimtriagelevel1unknownRes.png');});
timed_event(186303, function() { swap_icon(ems10, 'images/victimtriagelevel1unknownRes.png');});
timed_event(182196, function() { swap_icon(ems13, 'images/victimtriagelevel1unknownRes.png');});
timed_event(188871, function() { swap_icon(ems12, 'images/victimtriagelevel1unknownRes.png');});
timed_event(223758, function() { swap_icon(ems11, 'images/victimtriagelevel1unknownRes.png');});
timed_event(193248, function() { swap_icon(ems14, 'images/victimtriagelevel1unknownRes.png');});
timed_event(216306, function() { swap_icon(ems15, 'images/victimtriagelevel1unknownRes.png');});
timed_event(228867, function() { swap_icon(ems16, 'images/victimtriagelevel1unknownRes.png');});
timed_event(295182, function() { swap_icon(ems17, 'images/victimtriagelevel1unknownRes.png');});
timed_event(202839, function() { swap_icon(ems19, 'images/victimtriagelevel1unknownRes.png');});
timed_event(246306, function() { swap_icon(ems20, 'images/victimtriagelevel1unknownRes.png');});
timed_event(240678, function() { swap_icon(ems18, 'images/victimtriagelevel1unknownRes.png');});
timed_event(360690, function() { swap_icon(ems21, 'images/victimtriagelevel1unknownRes.png');});
timed_event(232839, function() { swap_icon(ems22, 'images/victimtriagelevel1unknownRes.png');});

//create grouped triage
timed_event(111599, function() { swap_icon(ems4, 'images/grouped.png');});
timed_event(114446, function() { swap_icon(ems3, 'images/grouped.png');});
timed_event(115355, function() { swap_icon(ems2, 'images/grouped.png');});
timed_event(117542, function() { swap_icon(ems1, 'images/grouped.png');});
timed_event(159794, function() { swap_icon(ems6, 'images/grouped.png');});
timed_event(152432, function() { swap_icon(ems5, 'images/grouped.png');});
timed_event(153686, function() { swap_icon(ems7, 'images/grouped.png');});
timed_event(161435, function() { swap_icon(ems8, 'images/grouped.png');});
timed_event(197624, function() { swap_icon(ems9, 'images/grouped.png');});
timed_event(196325, function() { swap_icon(ems10, 'images/grouped.png');});
timed_event(192218, function() { swap_icon(ems13, 'images/grouped.png');});
timed_event(198893, function() { swap_icon(ems12, 'images/grouped.png');});
timed_event(233780, function() { swap_icon(ems11, 'images/grouped.png');});
timed_event(203270, function() { swap_icon(ems14, 'images/grouped.png');});
timed_event(226328, function() { swap_icon(ems15, 'images/grouped.png');});
timed_event(238889, function() { swap_icon(ems16, 'images/grouped.png');});
timed_event(305204, function() { swap_icon(ems17, 'images/grouped.png');});
timed_event(212861, function() { swap_icon(ems19, 'images/grouped.png');});
timed_event(256328, function() { swap_icon(ems20, 'images/grouped.png');});
timed_event(250700, function() { swap_icon(ems18, 'images/grouped.png');});
timed_event(370712, function() { swap_icon(ems21, 'images/grouped.png');});
timed_event(242861, function() { swap_icon(ems22, 'images/grouped.png');});



//Create normal readings
timed_event(46500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16490148000173,  -86.78424596786499), 'images/HAZMATReading.png', 0)); });
timed_event(46502, function() { window.hazmat1 = last_item; });
timed_event(52500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164834352379856,  -86.78418159484863), 'images/HAZMATReading.png', 0)); });
timed_event(52502, function() { window.hazmat2 = last_item; });
timed_event(121500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164940457304205,  -86.78414672613144), 'images/HAZMATReading.png', 0)); });
timed_event(121502, function() { window.hazmat3 = last_item; });
timed_event(127498, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164884156749984,  -86.78409039974212), 'images/HAZMATReading.png', 0)); });
timed_event(127499, function() { window.hazmat4 = last_item; });
timed_event(196500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16498593079923,  -86.78400993347168), 'images/HAZMATReading.png', 0)); });
timed_event(196502, function() { window.hazmat5 = last_item; });
timed_event(202500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164944788114376,  -86.78392946720123), 'images/HAZMATReading.png', 0)); });
timed_event(202502, function() { window.hazmat6 = last_item; });
timed_event(271500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16502490805969,  -86.78390800952911), 'images/HAZMATReading.png', 0)); });
timed_event(271502, function() { window.hazmat7 = last_item; });
timed_event(277500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16500541943189,  -86.78380608558655), 'images/HAZMATReading.png', 0)); });
timed_event(277502, function() { window.hazmat8 = last_item; });
timed_event(346500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507254690726,  -86.78380876779556), 'images/HAZMATReading.png', 0)); });
timed_event(346502, function() { window.hazmat9 = last_item; });
timed_event(352500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165131012726086,  -86.78369075059891), 'images/HAZMATReading.png', 0)); });
timed_event(352502, function() { window.hazmat10 = last_item; });
timed_event(421500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.78366661071777), 'images/HAZMATReading.png', 0)); });
timed_event(421502, function() { window.hazmat11 = last_item; });
timed_event(427500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.78355932235718), 'images/HAZMATReading.png', 0)); });
timed_event(427502, function() { window.hazmat12 = last_item; });
timed_event(496500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16512235112605,  -86.78351640701294), 'images/HAZMATReading.png', 0)); });
timed_event(496502, function() { window.hazmat13 = last_item; });
timed_event(502500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78345203399658), 'images/HAZMATReading.png', 0)); });
timed_event(502502, function() { window.hazmat14 = last_item; });
timed_event(571500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.7834010720253), 'images/HAZMATReading.png', 0)); });
timed_event(571502, function() { window.hazmat15 = last_item; });
timed_event(577500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.78330451250076), 'images/HAZMATReading.png', 0)); });
timed_event(577502, function() { window.hazmat16 = last_item; });
timed_event(646500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78326427936554), 'images/HAZMATReading.png', 0)); });
timed_event(646502, function() { window.hazmat17 = last_item; });
timed_event(151500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16535188320363,  -86.78315162658691), 'images/HAZMATReading.png', 0)); });
timed_event(151502, function() { window.hazmat18 = last_item; });
timed_event(155100, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16526093661178,  -86.78318113088608), 'images/HAZMATReading.png', 0)); });
timed_event(155102, function() { window.hazmat19 = last_item; });
timed_event(196500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.7831140756607), 'images/HAZMATReading.png', 0)); });
timed_event(196502, function() { window.hazmat20 = last_item; });
timed_event(200100, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165172155313186,  -86.78311139345169), 'images/HAZMATReading.png', 0)); });
timed_event(200102, function() { window.hazmat21 = last_item; });
timed_event(241500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16521979407126,  -86.78304702043533), 'images/HAZMATReading.png', 0)); });
timed_event(241502, function() { window.hazmat22 = last_item; });
timed_event(245100, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16506821610414,  -86.78294241428375), 'images/HAZMATReading.png', 0)); });
timed_event(245102, function() { window.hazmat23 = last_item; });
timed_event(286500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165152666722,  -86.78300142288208), 'images/HAZMATReading.png', 0)); });
timed_event(286502, function() { window.hazmat24 = last_item; });
timed_event(290100, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.7830416560173), 'images/HAZMATReading.png', 0)); });
timed_event(290102, function() { window.hazmat25 = last_item; });
timed_event(331500, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165003254028484,  -86.78299069404602), 'images/HAZMATReading.png', 0)); });
timed_event(331502, function() { window.hazmat26 = last_item; });
timed_event(335100, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16495128432922,  -86.78291022777557), 'images/HAZMATReading.png', 0)); });
timed_event(335102, function() { window.hazmat27 = last_item; });

//Create residue readings
timed_event(61520, function() { swap_icon(hazmat1, 'images/HAZMATReadingRes.png');});
timed_event(67520, function() { swap_icon(hazmat2, 'images/HAZMATReadingRes.png');});
timed_event(136520, function() { swap_icon(hazmat3, 'images/HAZMATReadingRes.png');});
timed_event(142520, function() { swap_icon(hazmat4, 'images/HAZMATReadingRes.png');});
timed_event(211520, function() { swap_icon(hazmat5, 'images/HAZMATReadingRes.png');});
timed_event(217520, function() { swap_icon(hazmat6, 'images/HAZMATReadingRes.png');});
timed_event(286520, function() { swap_icon(hazmat7, 'images/HAZMATReadingRes.png');});
timed_event(292520, function() { swap_icon(hazmat8, 'images/HAZMATReadingRes.png');});
timed_event(361520, function() { swap_icon(hazmat9, 'images/HAZMATReadingRes.png');});
timed_event(367520, function() { swap_icon(hazmat10, 'images/HAZMATReadingRes.png');});
timed_event(436520, function() { swap_icon(hazmat11, 'images/HAZMATReadingRes.png');});
timed_event(442520, function() { swap_icon(hazmat12, 'images/HAZMATReadingRes.png');});
timed_event(511520, function() { swap_icon(hazmat13, 'images/HAZMATReadingRes.png');});
timed_event(517520, function() { swap_icon(hazmat14, 'images/HAZMATReadingRes.png');});
timed_event(586520, function() { swap_icon(hazmat15, 'images/HAZMATReadingRes.png');});
timed_event(592520, function() { swap_icon(hazmat16, 'images/HAZMATReadingRes.png');});
timed_event(661520, function() { swap_icon(hazmat17, 'images/HAZMATReadingRes.png');});
timed_event(166520, function() { swap_icon(hazmat18, 'images/HAZMATReadingRes.png');});
timed_event(170120, function() { swap_icon(hazmat19, 'images/HAZMATReadingRes.png');});
timed_event(211520, function() { swap_icon(hazmat20, 'images/HAZMATReadingRes.png');});
timed_event(215120, function() { swap_icon(hazmat21, 'images/HAZMATReadingRes.png');});
timed_event(256520, function() { swap_icon(hazmat22, 'images/HAZMATReadingRes.png');});
timed_event(260120, function() { swap_icon(hazmat23, 'images/HAZMATReadingRes.png');});
timed_event(301520, function() { swap_icon(hazmat24, 'images/HAZMATReadingRes.png');});
timed_event(305120, function() { swap_icon(hazmat25, 'images/HAZMATReadingRes.png');});
timed_event(346520, function() { swap_icon(hazmat26, 'images/HAZMATReadingRes.png');});
timed_event(350120, function() { swap_icon(hazmat27, 'images/HAZMATReadingRes.png');});

//Create grouped readings
timed_event(297525, function() { swap_icon(hazmat1, 'images/grouped.png');});
timed_event(297530, function() { swap_icon(hazmat2, 'images/grouped.png');});
timed_event(297535, function() { swap_icon(hazmat3, 'images/grouped.png');});
timed_event(297540, function() { swap_icon(hazmat4, 'images/grouped.png');});
timed_event(297545, function() { swap_icon(hazmat5, 'images/grouped.png');});
timed_event(297550, function() { swap_icon(hazmat6, 'images/grouped.png');});
timed_event(297555, function() { swap_icon(hazmat7, 'images/grouped.png');});
timed_event(297560, function() { swap_icon(hazmat8, 'images/grouped.png');});
timed_event(676535, function() { swap_icon(hazmat9, 'images/grouped.png');});
timed_event(676540, function() { swap_icon(hazmat10, 'images/grouped.png');});
timed_event(676545, function() { swap_icon(hazmat11, 'images/grouped.png');});
timed_event(676550, function() { swap_icon(hazmat12, 'images/grouped.png');});
timed_event(676555, function() { swap_icon(hazmat13, 'images/grouped.png');});
timed_event(676560, function() { swap_icon(hazmat14, 'images/grouped.png');});
timed_event(676565, function() { swap_icon(hazmat15, 'images/grouped.png');});
timed_event(676570, function() { swap_icon(hazmat16, 'images/grouped.png');});
timed_event(676575, function() { swap_icon(hazmat17, 'images/grouped.png');});
timed_event(365135, function() { swap_icon(hazmat18, 'images/grouped.png');});
timed_event(365140, function() { swap_icon(hazmat19, 'images/grouped.png');});
timed_event(365145, function() { swap_icon(hazmat20, 'images/grouped.png');});
timed_event(365150, function() { swap_icon(hazmat21, 'images/grouped.png');});
timed_event(365155, function() { swap_icon(hazmat22, 'images/grouped.png');});
timed_event(365160, function() { swap_icon(hazmat23, 'images/grouped.png');});
timed_event(365165, function() { swap_icon(hazmat24, 'images/grouped.png');});
timed_event(365170, function() { swap_icon(hazmat25, 'images/grouped.png');});
timed_event(365175, function() { swap_icon(hazmat26, 'images/grouped.png');});
timed_event(365180, function() { swap_icon(hazmat27, 'images/grouped.png');});

//Create Reading grouped areas
 timed_event(297527, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.16492963027768,  -86.78432643413543),
                 new google.maps.LatLng(36.16511368952505,  -86.78389191627502),
                 new google.maps.LatLng(36.1650314042679,  -86.78372025489807),
                 new google.maps.LatLng(36.164806202069705,  -86.78419232368469)], null, '#ff3366')); });  
timed_event(297528, function() { window.hazmatGroup1 = last_item; });
 timed_event(676537, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.165130290937135,  -86.78393751382828),
                 new google.maps.LatLng(36.16501552465791,  -86.783706843853),
                 new google.maps.LatLng(36.16520391449947,  -86.78318917751312),
                 new google.maps.LatLng(36.16538797310278,  -86.78330183029175)], null, '#ff7866')); });  
timed_event(676538, function() { window.hazmatGroup2 = last_item; });
 timed_event(365137, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
                [new google.maps.LatLng(36.1653123431031,  -86.7832213640213),
                 new google.maps.LatLng(36.1648817314885,  -86.78294509649277),
                 new google.maps.LatLng(36.16494019744963,  -86.78280830383301),
                 new google.maps.LatLng(36.165409785812145,  -86.78317308425903)], null, '#ffb066')); });  
timed_event(365138, function() { window.hazmatGroup3 = last_item; });


//hazmat_5 & _6 move around
timed_event(6000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16490148000173,  -86.78424596786499)); });
timed_event(7000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164834352379856,  -86.78418159484863)); });
timed_event(51000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.164940457304205,  -86.78414672613144)); });
timed_event(57000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164884156749984,  -86.78409039974212)); });
timed_event(126000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16498593079923,  -86.78400993347168)); });
timed_event(132000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164944788114376,  -86.78392946720123)); });
timed_event(201000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16502490805969,  -86.78390800952911)); });
timed_event(207000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16500541943189,  -86.78380608558655)); });
timed_event(276000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16507254690726,  -86.78380876779556)); });
timed_event(282000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.165131012726086,  -86.78369075059891)); });
timed_event(351000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16507471230873,  -86.78366661071777)); });
timed_event(357000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16518081690772,  -86.78355932235718)); });
timed_event(426000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16512235112605,  -86.78351640701294)); });
timed_event(432000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16523711724884,  -86.78345203399658)); });
timed_event(501000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16518081690772,  -86.7834010720253)); });
timed_event(507000, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.165293417549556,  -86.78330451250076)); });
timed_event(576000, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16523711724884,  -86.78326427936554)); });

//hazmat_3 & _4 move around
timed_event(30000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16534408778476, -86.78323209285736)); });
timed_event(30000, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16530727607808, -86.78321868181228)); });
timed_event(156000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165293417549556,  -86.7831140756607)); });
timed_event(159600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.165172155313186,  -86.78311139345169)); });
timed_event(201000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16521979407126,  -86.78304702043533)); });
timed_event(204600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16506821610414,  -86.78294241428375)); });
timed_event(246000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165152666722,  -86.78300142288208)); });
timed_event(249600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16507471230873,  -86.7830416560173)); });
timed_event(291000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165003254028484,  -86.78299069404602)); });
timed_event(294600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16495128432922,  -86.78291022777557)); });
timed_event(582000, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16494669366483, -86.78284853696823)); });
timed_event(651000, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16490771636549, -86.78291827440262)); });

//ems_1
timed_event(18000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16503114441775, -86.7833286523819)); });
timed_event(33000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16481027303645, -86.78366124629974)); });
timed_event(48000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16491854339916, -86.78325086832046)); });
timed_event(63000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164704167935895, -86.78357809782028)); });
timed_event(78000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16478645353657, -86.78317040205002)); });
timed_event(93000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164530934809996, -86.78357005119324)); });
timed_event(108000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16466302510316, -86.78308725357055)); });
timed_event(123000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16443782184663, -86.78347885608673)); });
timed_event(138000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164587235617894, -86.7830416560173)); });
timed_event(153000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16432738539786, -86.78335547447204)); });
timed_event(168000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16444648352228, -86.7829504609108)); });
timed_event(183000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16414982058538, -86.78324550390243)); });
timed_event(198000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164277580673975, -86.78283244371414)); });
timed_event(213000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16401989485804, -86.78319990634918)); });
timed_event(228000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16416497857288, -86.78275734186172)); });
timed_event(273000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16410218117704, -86.78273320198059)); });
timed_event(279000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16380335150054, -86.78355664014816)); });
timed_event(312000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164015563996756, -86.78293973207474)); });
timed_event(327000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1638336676066, -86.78302824497223)); });
timed_event(342000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.163775200820154, -86.7833662033081)); });
timed_event(357000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16371889942899, -86.78350567817688)); });
timed_event(372000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.163595469314586, -86.7835083603859)); });
timed_event(417000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164032887440456, -86.78245157003402)); });
timed_event(450000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16417147485235, -86.78229331970215)); });
timed_event(457500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16412600088482, -86.78255617618561)); });
timed_event(465000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1642645881321, -86.78237110376358)); });
timed_event(472500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16420395624157, -86.78258836269378)); });
timed_event(480000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164316558286636, -86.78238987922668)); });
timed_event(487500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1642710844033, -86.78264200687408)); });
timed_event(495000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16437719009009, -86.7824274301529)); });
timed_event(502500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164318723709, -86.78267687559128)); });
timed_event(510000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16443782184663, -86.7824649810791)); });
timed_event(517500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16440317513434, -86.7827358841896)); });
timed_event(525000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16464137097198, -86.78259640932083)); });
timed_event(532500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16465003262517, -86.78289949893951)); });
timed_event(540000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164788618945955, -86.78270906209945)); });
timed_event(547500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16476263402947, -86.78297460079193)); });
timed_event(555000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164883896899354, -86.78280025720596)); });
timed_event(562500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164873069865024, -86.78303360939026)); });
timed_event(570000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16500082877481, -86.78285390138626)); });
timed_event(577500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16496185150239, -86.7830953001976)); });
timed_event(585000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16507878326153, -86.78290218114853)); });
timed_event(592500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.165028979015084, -86.78314357995987)); });
timed_event(600000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16518705325337, -86.7829692363739)); });
timed_event(607500, function() { trigger(map, 'move_item', ems_1, new LatLng(36.165128587476346, -86.7832213640213)); });
timed_event(615000, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16527583453509, -86.78304970264435)); });

//ems_2
timed_event(66000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165173021472754,  -86.78323745727539)); });
timed_event(87000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16525097578823,  -86.78301483392715)); });
timed_event(108000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165116721085575,  -86.78321063518524)); });
timed_event(129000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16518384846566,  -86.78297191858291)); });
timed_event(150000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16505392445218,  -86.78318917751312)); });
timed_event(171000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16512321728617,  -86.78293168544769)); });
timed_event(192000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16499762397949,  -86.78313821554184)); });
timed_event(213000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165073413067944,  -86.78289145231247)); });
timed_event(234000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16491966941206,  -86.78307920694351)); });
timed_event(255000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16498463155697,  -86.78281635046005)); });
timed_event(276000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164861203435606,  -86.78304702043533)); });
timed_event(297000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164947819681444,  -86.782805621624)); });
timed_event(318000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164830887726936,  -86.78300946950912)); });
timed_event(339000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164904511570484,  -86.78277611732483)); });
timed_event(360000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16479624118838,  -86.78296387195587)); });
timed_event(381000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16485254180575,  -86.78274393081665)); });
timed_event(402000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.1647464367624,  -86.78291827440262)); });
timed_event(423000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16480057200654,  -86.78270637989044)); });
timed_event(444000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164687970656736,  -86.78288608789444)); });
timed_event(465000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16476159463453,  -86.78267687559128)); });
timed_event(486000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16462950450747,  -86.78284853696823)); });
timed_event(507000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16470745936347,  -86.78263664245605)); });
timed_event(528000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164623008265956,  -86.78284049034118)); });
timed_event(549000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16468580524458,  -86.78263127803802)); });
timed_event(570000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16456670748376,  -86.7828243970871)); });
timed_event(591000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164648993228724,  -86.78261250257492)); });
timed_event(612000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164425955351284,  -86.78276002407074)); });
timed_event(633000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16449091790537,  -86.7825186252594)); });
timed_event(654000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16437398526926,  -86.7826983332634)); });
timed_event(675000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16441729367334,  -86.78247034549713)); });
timed_event(696000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16429386465862,  -86.78265810012817)); });
timed_event(717000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16436748900657,  -86.78243815898895)); });
timed_event(738000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164237563640015,  -86.78262323141098)); });
timed_event(759000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16432851141923,  -86.78240865468979)); });
timed_event(780000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164213743966094,  -86.78259909152984)); });
timed_event(801000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16428736838932,  -86.78237915039062)); });
timed_event(822000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16420291683922,  -86.78258568048477)); });
timed_event(843000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16426787957814,  -86.78235501050949)); });
timed_event(864000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16417260087596,  -86.7825910449028)); });
timed_event(885000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16425272161054,  -86.78233623504638)); });
timed_event(906000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16414445032816,  -86.78258299827575)); });
timed_event(927000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16422024024153,  -86.78232282400131)); });
timed_event(948000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16411413434228,  -86.78256154060364)); });
timed_event(969000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16418775885906,  -86.78229600191116)); });
timed_event(990000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164064329482926,  -86.78251594305038)); });
timed_event(1011000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16413145776422,  -86.78228259086609)); });
timed_event(1032000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16405350233539,  -86.78250521421432)); });
timed_event(1053000, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16456021123705,  -86.78329646587372)); });

//ems_3
timed_event(33000, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16500732498088,  -86.78372293710708)); });
timed_event(57000, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16494019744963,  -86.7835459113121)); });
timed_event(64101, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16499242701067,  -86.78335279226303)); });
timed_event(109107, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16476289388051,  -86.78346008062362)); });
timed_event(144777, function() { trigger(map, 'move_item', ems_3, new LatLng(36.1646648873718,  -86.78337961435318)); });
timed_event(149532, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16462647292811,  -86.78330719470978)); });
timed_event(182607, function() { trigger(map, 'move_item', ems_3, new LatLng (36.164539856327146,  -86.783167719841)); });
timed_event(218763, function() { trigger(map, 'move_item', ems_3, new LatLng(36.164461338307554,  -86.7832562327385)); });
timed_event(253200, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16429083306628,  -86.78318113088608)); });
timed_event(290187, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16417364027459,  -86.78309261798858)); });
timed_event(325695, function() { trigger(map, 'move_item', ems_3, new LatLng (36.164267013408576,  -86.78286999464035)); });

//ems_4
timed_event(36000, function() { trigger(map, 'move_item', ems_4, new LatLng(36.1650463022307,  -86.78369343280792)); });
timed_event(60000, function() { trigger(map, 'move_item', ems_4, new LatLng(36.16494019744963,  -86.7835459113121)); });
timed_event(66813, function() { trigger(map, 'move_item', ems_4, new LatLng (36.164940457304226,  -86.78347617387771)); });
timed_event(99429, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16474557059812,  -86.78356200456619)); });
timed_event(137415, function() { trigger(map, 'move_item', ems_4, new LatLng(36.16465406030728,  -86.78335011005401)); });
timed_event(146070, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16464596165013,  -86.78321063518524)); });
timed_event(181308, function() { trigger(map, 'move_item', ems_4, new LatLng (36.1644640667228,  -86.78324550390243)); });
timed_event(188253, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16421287779595,  -86.78319722414017)); });
timed_event(197844, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16404180901432,  -86.78310066461563)); });

//ems_5
timed_event(39000, function() { trigger(map, 'move_item', ems_5, new LatLng(36.16504413682844,  -86.78365588188171)); });
timed_event(63000, function() { trigger(map, 'move_item', ems_5, new LatLng (36.1648754951227,  -86.78355664014816)); });
timed_event(100338, function() { trigger(map, 'move_item', ems_5, new LatLng (36.164674112017835,  -86.78346276283264)); });
timed_event(138669, function() { trigger(map, 'move_item', ems_5, new LatLng (36.1644575704676,  -86.78339302539825)); });
timed_event(177201, function() { trigger(map, 'move_item', ems_5, new LatLng (36.16438611162475,  -86.78330987691879)); });
timed_event(211311, function() { trigger(map, 'move_item', ems_5, new LatLng (36.164195554392016,  -86.78305774927139)); });

//ems_6
timed_event(42000, function() { trigger(map, 'move_item', ems_6, new LatLng(36.16504413682844,  -86.78365588188171)); });
timed_event(66000, function() { trigger(map, 'move_item', ems_6, new LatLng (36.164871164308664,  -86.78363710641861)); });
timed_event(102525, function() { trigger(map, 'move_item', ems_6, new LatLng (36.164604818786834,  -86.78337961435318)); });
timed_event(146418, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16445323963048,  -86.7835083603859)); });
timed_event(183876, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16436662283812,  -86.7832562327385)); });
timed_event(223872, function() { trigger(map, 'move_item', ems_6, new LatLng(36.164457007458786,  -86.78322404623031)); });
timed_event(227469, function() { trigger(map, 'move_item', ems_6, new LatLng(36.16454362415128,  -86.7830228805542)); });
timed_event(235683, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16435796115361,  -86.78290218114853)); });

//hazmat_1 & _2
timed_event(20572, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.16426138330668, -86.7828431725502)); });
timed_event(45572, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.164341503950496, -86.78346812725067)); });
timed_event(88030, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.164672812770384, -86.78213238716125)); });
timed_event(122275, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.16486769965735, -86.7832401394844)); });
timed_event(139966, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.16513620968572, -86.78339302539825)); });
timed_event(131829, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.163802312092876, -86.78354322910309)); });
timed_event(201889, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.16398637398733, -86.78294509649277)); });



//remainder, not even rolled in glitter
timed_event(15275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16426138330668, -86.7828431725502), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(15276, function() { window.suspObj5 = last_item; });
timed_event(45275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(45276, function() { window.suspObj3 = last_item; });
timed_event(57275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164672812770384, -86.78213238716125), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(57276, function() { window.suspObj7 = last_item; });
timed_event(121275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486769965735, -86.7832401394844), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(121276, function() { window.suspObj2 = last_item; });
timed_event(126275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16513620968572, -86.78339302539825), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(126276, function() { window.suspObj1 = last_item; });
timed_event(130275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.163802312092876, -86.78354322910309), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(130276, function() { window.suspObj6 = last_item; });
timed_event(200275, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16398637398733, -86.78294509649277), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
timed_event(200276, function() { window.suspObj4 = last_item; });



//delete identified non-threats
timed_event(87030, function() { trigger(map, 'delete_item', suspObj5); });
timed_event(201889, function() { trigger(map, 'delete_item', suspObj1); });
timed_event(130829, function() { trigger(map, 'delete_item', suspObj6); });
timed_event(121275, function() { swap_icon(suspObj3, 'images/suspiciousitem.png');});
timed_event(121275, function() { swap_icon(suspObj2, 'images/suspiciousitem.png');});
timed_event(121275, function() { swap_icon(suspObj4, 'images/suspiciousitem.png');});



//TIMING BELOW IS JANKY
//Suspicious Object 3 is a bomb - Should start at about 78000?
timed_event(121275, function() { swap_icon(3, 'images/suspiciousitem.png');});



// timed_event(432600, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16472536010817, -86.78285390138626)); });
// timed_event(447600, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16445251783528, -86.78329110145569)); });
// timed_event(453600, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.164341503950496, -86.78346812725067)); });

// timed_event(633657, function() { 
//     trigger(map, 'delete_item', suspObj3);
//     trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/bomb.png', 40));
//     window.suspObj3 = last_item; 
//});

// //Suspicious Object 7 is found to be harmless
// timed_event(376857, function() { trigger(map, 'delete_item', suspObj7); });
// timed_event(376860, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164672812770384, -86.78213238716125), 'images/suspiciousitem.png', 20)); });
// timed_event(376866, function() { window.suspObj7 = last_item; });
//     timed_event(126193, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
//         [new google.maps.LatLng(36.16470200252005, -86.78218334913254), 
//          new google.maps.LatLng(36.16473015286763, -86.78211361169815), 
//          new google.maps.LatLng(36.164680348399635, -86.78208410739898), 
//          new google.maps.LatLng(36.16466085968619, -86.7821404337883)], affiliation.HAZMAT)); });
// timed_event(378582, function() { window.hazmatTask4 = last_item; });

// timed_event(480600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16477296302341, -86.78277343511581)); });
// timed_event(486600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.1648379252899, -86.78246229887009)); });
// timed_event(495600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.164792451709026, -86.78237646818161)); });
// timed_event(501600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16484225610577, -86.78224235773087)); });
// timed_event(507600, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.164672812770384, -86.78213238716125)); });

// timed_event(687657, function() { 
//     trigger(map, 'delete_item', suspObj7);
//     trigger(map, 'delete_item', hazmatTask4); 
// });

// //Suspicious Object 2 is a bomb
// timed_event(466860, function() { 
//     trigger(map, 'delete_item', suspObj2);
//     trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486224282507, -86.78327232599258), 'images/suspiciousitem.png', 20));
//     window.suspObj2 = last_item; 
// });
// timed_event(468579, function() { 
//     trigger(map, 'add_item', task_area, task_area_options_template(map,
//         [new google.maps.LatLng(36.16483625793713, -86.78317844867706), 
//          new google.maps.LatLng(36.16482110007946, -86.78323209285736), 
//          new google.maps.LatLng(36.16490988177564, -86.7832937836647), 
//          new google.maps.LatLng(36.164935866643326, -86.78321063518524)], affiliation.HAZMAT));
//     window.hazmatTask5 = last_item; 
// });

// timed_event(474600, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16505230038737, -86.78364515304565)); });
// timed_event(489600, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16490072209634, -86.78351372480392)); });
// timed_event(498600, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.164987338298545, -86.78332328796387)); });
// timed_event(504600, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16492890848688, -86.78328305482864)); });

// timed_event(687657, function() { 
//     trigger(map, 'delete_item', suspObj2);
//     trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486224282507, -86.78327232599258), 'images/bomb.png', 40));
//     window.suspObj2 = last_item; 
// });

// timed_event(979857, function() { 
//     trigger(map, 'delete_item', suspObj4);
//     trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.1639852479569, -86.78297191858291), 'images/suspiciousitem.png', 20));
//     window.suspObj4 = last_item; 
// });

// timed_event(981582, function() { 
//     trigger(map, 'add_item', task_area, task_area_options_template(map,
//         [new google.maps.LatLng(36.16404371459084, -86.78299605846405), 
//          new google.maps.LatLng(36.164076600992345, -86.78293832184113), 
//          new google.maps.LatLng(36.16401989485804, -86.78287267684936), 
//          new google.maps.LatLng(36.163989578823994, -86.78294777870178)], affiliation.HAZMAT));
//     window.hazmatTask6 = last_item; 
//     //!!    
//     // trigger(map, 'move_item', hazmat_6, new LatLng(36.165024150155496, -86.78368538618088));
//     trigger(map, 'move_item', hazmat_6, new LatLng(36.164341503950496, -86.78346812725067));
// });
// timed_event(1170657, function() { 
//     trigger(map, 'delete_item', suspObj4);
//     trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.1639852479569, -86.78297191858291), 'images/bomb.png', 40));
//     window.suspObj4 = last_item; 
// });


//*******************************************************************************************************************
//*******************************************************************************************************************
//End paste from excel

//*******************************************************************************************************************
//*******************************************************************************************************************

}
google.maps.event.addDomListener(window, 'load', scenario_2);   // Note: order of listeners may not be guaranteed