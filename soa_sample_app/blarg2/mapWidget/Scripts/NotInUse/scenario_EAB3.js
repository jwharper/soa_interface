function scenario_2() {
    var time;
    var trigger = google.maps.event.trigger;
    var LatLng = google.maps.LatLng;
    var coefficient= 4;
    ///var probeLabel = document.getElementById("probe");
    function add_robot(lat, lng, affiliation, type) {
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(lat, lng), affiliation, type)); 
    }
    time = 0;

    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16513620968572, -86.78339302539825), 'images/a1.png', 0)); });
    // timed_event(0, function() { window.suspObj1 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486769965735, -86.7832401394844), 'images/a2.png', 0)); });
    // timed_event(0, function() { window.suspObj2 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/a3.png', 0)); });
    // timed_event(0, function() { window.suspObj3 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16398637398733, -86.78294509649277), 'images/a4.png', 0)); });
    // timed_event(0, function() { window.suspObj4 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16426138330668, -86.7828431725502), 'images/a5.png', 0)); });
    // timed_event(0, function() { window.suspObj5 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.163802312092876, -86.78354322910309), 'images/a6.png', 0)); });
    // timed_event(0, function() { window.suspObj6 = last_item; });
    // timed_event(0, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164672812770384, -86.78213238716125), 'images/a7.png', 0)); });
    // timed_event(0, function() { window.suspObj7 = last_item; });

    timed_event(time, function() { 
        add_robot(36.16408944845936, -86.7821404337883, affiliation.POLICE, robot_type.UAV); window.police_1 = last_item;
        add_robot(36.164037478154206, -86.78210288286209, affiliation.POLICE, robot_type.UAV); window.police_2 = last_item;

        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16406129788169, -86.78223967552185), affiliation.POLICE, robot_type.UAV));
        window.police_3 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16399633497156, -86.78219944238663), affiliation.POLICE, robot_type.UAV));
        window.police_4 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16477588633977, -86.78456246852875), affiliation.HAZMAT, robot_type.UAV));
        window.hazmat_1 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16473041272289, -86.78447127342224), affiliation.HAZMAT, robot_type.UAV));
        window.hazmat_2 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16482785615534, -86.78445786237716), affiliation.HAZMAT, robot_type.UGV));
        window.hazmat_3 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.164784547978094, -86.78441762924194), affiliation.HAZMAT, robot_type.UGV));
        window.hazmat_4 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16487332971568, -86.78437739610672), affiliation.HAZMAT, robot_type.UGV));
        window.hazmat_5 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16480911980213, -86.78433688295547), affiliation.HAZMAT, robot_type.UGV));
        window.hazmat_6 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16539519106742, -86.78292632102966), affiliation.EMS, robot_type.UAV));
        window.ems_1 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.1654861375035, -86.78298532962799), affiliation.EMS, robot_type.UAV));
        window.ems_2 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.16544282968993, -86.78305774927139), affiliation.EMS, robot_type.UGV));
        window.ems_3 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.165354048597365, -86.78301483392715), affiliation.EMS, robot_type.UGV));
        window.ems_4 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.165393025674774, -86.78318649530411), affiliation.EMS, robot_type.UGV));
        window.ems_5 = last_item;
        trigger(map, 'add_item', robot, robot_options_template(map, new LatLng(36.1653042445258, -86.78309798240661), affiliation.EMS, robot_type.UGV));
        window.ems_6 = last_item;
    });

    time = 3000;
    timed_event(time, function() { 
        police_1.setIcon({
            url: 'images/victimtriagelevelunknownunknownRes.png',
            scaledSize: police_1.icon.scaledSize
        });
    });

   /*
    time = 1400*coefficient;
    //
    //top left
    timed_event(time, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16457640853847, -86.78324818611145), 
         new google.maps.LatLng(36.16407619603713, -86.78464829921722), 
         new google.maps.LatLng(36.16503330982449, -86.78550124168396), 
         new google.maps.LatLng(36.165522689281815, -86.78413063287735)], affiliation.POLICE)); });
    timed_event(time, function() { window.policeTask1 = last_item; });    
	timed_event(time, function() { police_4.task = 'Search'; });

    //top right
    timed_event(time, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16461971683485, -86.7832025885582), 
         new google.maps.LatLng(36.16532130783554, -86.78155303001404),  
         new google.maps.LatLng(36.16612466513974, -86.7821940779686),
         new google.maps.LatLng(36.165628793270265, -86.78394019603729)], affiliation.POLICE)); });
    timed_event(time, function() { window.policeTask2 = last_item; });   
	timed_event(time, function() { police_1.task = 'Search'; });

    //bottom right
    timed_event(time, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16520437644026, -86.78155303001404), 
         new google.maps.LatLng(36.16461105519069, -86.78317844867706),
         new google.maps.LatLng(36.16353483691889, -86.78231745958328),  
         new google.maps.LatLng(36.164039383743265, -86.78077518939972)], affiliation.POLICE)); });
    timed_event(time, function() { window.policeTask3 = last_item; });   
	timed_event(time, function() { police_2.task = 'Search'; });


    //bottom left
    timed_event(time, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16459589728945, -86.78322404623031), 
         new google.maps.LatLng(36.16395709735834, -86.78464025259018), 
         new google.maps.LatLng(36.16282673353819, -86.78402870893478), 
         new google.maps.LatLng(36.16330096861985, -86.78251057863235)], affiliation.POLICE)); });
    timed_event(time, function() { window.policeTask4 = last_item; });   
	timed_event(time, function() { police_3.task = 'Search'; });

    //Charlotte Avenue
    timed_event(5595*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16494885907391, -86.78434520959854), 
         new google.maps.LatLng(36.16478645353657, -86.78422719240188), 
         new google.maps.LatLng(36.16521736882428, -86.78320527076721), 
         new google.maps.LatLng(36.16536678110966, -86.78335815668106)], affiliation.HAZMAT)); });
    timed_event(5597*coefficient, function() { window.hazmatTask1 = last_item; }); 
	timed_event(5598*coefficient, function() { hazmat_5.task = 'Gather Samples'; });
	timed_event(5598*coefficient, function() { hazmat_6.task = 'Gather Samples'; });

    timed_event(147000*coefficient, function() { trigger(map, 'delete_item', hazmatTask1); });

    //6th Avenue North
    timed_event(29590*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16536894649887, -86.78328305482864), 
         new google.maps.LatLng(36.16544040444572, -86.78310871124267), 
         new google.maps.LatLng(36.164379355506654, -86.78248107433319), 
         new google.maps.LatLng(36.16432955081577, -86.7826098203659)], affiliation.HAZMAT)); });
    timed_event(29592*coefficient, function() { window.hazmatTask2 = last_item; });
	timed_event(29593*coefficient, function() { hazmat_4.task = 'Gather Samples'; });
	timed_event(29593*coefficient, function() { hazmat_3.task = 'Gather Samples'; });

    timed_event(137000*coefficient, function() { trigger(map, 'delete_item', hazmatTask2); });

    //SA Probes; debug only
    timed_event(25000*coefficient, function() { setProbe("Neglect event; prompt if user fails to click"); });
    timed_event(20000*coefficient, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
    timed_event(37000*coefficient, function() { setProbe("Fault event; prompt if user fails to click"); });
    timed_event(46000*coefficient, function() { setProbe("Ask user if any of their robots are near high risk item"); });
    timed_event(50000*coefficient, function() { setProbe("False neglect/fault event; ask user if if any of their robots require attention"); });
    timed_event(80000*coefficient, function() { setProbe("Fault event; prompt if user fails to click"); });
    timed_event(92000*coefficient, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
    timed_event(97000*coefficient, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
    timed_event(125000*coefficient, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
    timed_event(147000*coefficient, function() { setProbe("Neglect event; prompt if user fails to click"); });
    timed_event(160000*coefficient, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
    timed_event(176000*coefficient, function() { setProbe("Fault event; prompt if user fails to click"); });
    timed_event(184000*coefficient, function() { setProbe("False outteam proximity; ask user if if any of their robots are near other team's robots"); });
    timed_event(195000*coefficient, function() { setProbe("Ask user if any of their robots are near high risk item"); });
    timed_event(216000*coefficient, function() { setProbe("False outteam proximity; ask user if if any of their robots are near other team's robots"); });
    timed_event(230000*coefficient, function() { setProbe("False neglect/fault event; ask user if if any of their robots require attention"); });
    timed_event(268000*coefficient, function() { setProbe("Neglect event; prompt if user fails to click"); });
    timed_event(328000*coefficient, function() { setProbe("False high risk; ask user if if any of their robots are near high risk item"); });
    timed_event(328000*coefficient, function() { setProbe("Ask user if any of their robots are near other teams' robots"); });
    timed_event(328000*coefficient, function() { setProbe("False outteam proximity; ask user if if any of their robots are near other team's robots"); });

    //Search for victims
    timed_event(5790*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16485141579189, -86.78380340337753), 
         new google.maps.LatLng(36.16517839165954, -86.78325086832046), 
         new google.maps.LatLng(36.16402855657988, -86.78251057863235),
         new google.maps.LatLng(36.163610627409284, -86.78348422050476),
         new google.maps.LatLng(36.1638055169371, -86.78360491991043), 
         new google.maps.LatLng(36.164002571411444, -86.7831489443779)], affiliation.EMS)); });
    timed_event(5792*coefficient, function() { window.emsTask1 = last_item; });(36.164032887440456, -86.78245157003402)
    timed_event(142000*coefficient, function() { trigger(map, 'delete_item', hazmatTask1); });
	timed_event(5793*coefficient, function() { ems_1.task = 'Victim Search'; });

    //Triage Victims 1
    timed_event(11400*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.1650376406213, -86.7833286523819), 
         new google.maps.LatLng(36.1648752352679, -86.78372025489807), 
         new google.maps.LatLng(36.164706333343396, -86.78359150886535),
         new google.maps.LatLng(36.16484491956465, -86.78319990634918)], affiliation.EMS)); });
    timed_event(11402*coefficient, function() { window.emsTask2 = last_item; });
	timed_event(11403*coefficient, function() { ems_3.task = 'Triage Victims'; });
	timed_event(11403*coefficient, function() { ems_4.task = 'Triage Victims'; });
	timed_event(11403*coefficient, function() { ems_5.task = 'Triage Victims'; });
	timed_event(11403*coefficient, function() { ems_6.task = 'Triage Victims'; });

    timed_event(27399*coefficient, function() { trigger(map, 'delete_item', emsTask2); });

    //Triage Victims 2
    timed_event(27400*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.1650376406213, -86.7833286523819), 
         new google.maps.LatLng(36.1648752352679, -86.78372025489807), 
         new google.maps.LatLng(36.16409351945917, -86.78319454193115),
         new google.maps.LatLng(36.16425592643219, -86.7828243970871)], affiliation.EMS)); });
    timed_event(27402*coefficient, function() { window.emsTask3 = last_item; });

	//Police UAVs fly around
    timed_event(2000*coefficient, function() { trigger(map, 'move_item', police_1, new LatLng(36.1646437962368, -86.78313553333282)); });
	timed_event(2000*coefficient, function() { trigger(map, 'move_item', police_2, new LatLng(36.16458749546951, -86.78310066461563)); });
	timed_event(2000*coefficient, function() { trigger(map, 'move_item', police_3, new LatLng(36.16452469841214, -86.78325891494751)); });
	timed_event(2000*coefficient, function() { trigger(map, 'move_item', police_4, new LatLng(36.16458316463957, -86.78329110145569)); });

	time = 5010*coefficient;

    timed_event(time, function() { hazmat_1.speed /= coefficient; });
    timed_event(time, function() { hazmat_2.speed /= coefficient; });
    timed_event(time, function() { hazmat_3.speed /= coefficient; });
    timed_event(time, function() { hazmat_4.speed /= coefficient; });
    timed_event(time, function() { hazmat_5.speed /= coefficient; });
    timed_event(time, function() { hazmat_6.speed /= coefficient; });

    timed_event(time, function() { ems_1.speed /= coefficient; });
    timed_event(time, function() { ems_2.speed /= coefficient; });
    timed_event(time, function() { ems_3.speed /= coefficient; });
    timed_event(time, function() { ems_4.speed /= coefficient; });
    timed_event(time, function() { ems_5.speed /= coefficient; });
    timed_event(time, function() { ems_6.speed /= coefficient; });
    
	timed_event(time, function() { police_1.speed /= 3 * coefficient; });
	timed_event(time, function() { police_2.speed /= 3 * coefficient; });
	timed_event(time, function() { police_3.speed /= 3 * coefficient; });
	timed_event(time, function() { police_4.speed /= 3 * coefficient; });
	timed_event(time, function() { police_4.task = 'some task'; });

	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165315071500586, -86.78171932697296)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.164856006457725, -86.78322941064835)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165507791401275, -86.78190171718597)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16499675781797, -86.78330987691879)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.165715668515794, -86.78204119205475)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16515890308227, -86.78356468677521)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16585399311749, -86.78214848041534)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16533430021465, -86.7837256193161)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16604238094385, -86.78223967552185)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16557032783512, -86.78387850522995)); }); }); });
	timed_event(time, function() { trigger(police_1, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_1, new LatLng(36.16530831547907, -86.78316235542297)); }); }); });

	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16458749546951, -86.78310066461563)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16502707346249, -86.78156107664108)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16434280320342, -86.78293436765671)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16484734482729, -86.78143233060837)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16416307299929, -86.78280293941498)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16454418715945, -86.78123384714127)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16389646522996, -86.78259640932083)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.164375024681725, -86.78110241889953)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16365826712878, -86.78243279457092)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16419962540282, -86.78097367286682)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.1635001898075, -86.78236037492752)); }); }); });
	timed_event(time, function() { trigger(police_2, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_2, new LatLng(36.16399607513039, -86.78230673074722)); }); }); });

	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16452469841214, -86.78325891494751)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163842589203114, -86.78448736667633)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.164236697470095, -86.78308725357056)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16358273651459, -86.78439617156982)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.164054801593096, -86.78294777870178)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163353199256576, -86.78424060344696)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163859652843435, -86.78299069404602)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16317320693955, -86.7841386795044)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163593303884646, -86.78291022777557)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16297398492088, -86.78410917520523)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.16331829222148, -86.7826983332634)); }); }); });
	timed_event(time, function() { trigger(police_3, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_3, new LatLng(36.163491528027265, -86.78351372480392)); }); }); });

	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16458316463957, -86.78329110145569)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16410677188674, -86.78464829921722)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.164743405187544, -86.7834198474884)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16425402086494, -86.78476095199585)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16487766052959, -86.78350567817688)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16444457795554, -86.78488433361053)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16501382119878, -86.78378731012344)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.1645937318665, -86.78497821092605)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16525851137018, -86.7839053273201)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.164851415796036, -86.78524106740951)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.165429577496525, -86.78402066230774)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16500082877895, -86.78536981344223)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.165498869998416, -86.78416281938553)); }); }); });
	timed_event(time, function() { trigger(police_4, 'push_event', function() { timed_event(500, function() {trigger(map, 'move_item', police_4, new LatLng(36.16479078435941, -86.78435325622558)); }); }); });

    //Pasted in from excel

    //Create normal victims
    timed_event(11000*coefficient, function() { 
        trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16499242701067,  -86.78335279226303), 'images/victimtriagelevelunknownunknown.png', 0)); 
        window.ems4 = last_item;
    });
    // timed_event(11002*coefficient, function() {  });
    timed_event(12000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164940457304226,  -86.78347617387771), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(12002*coefficient, function() { window.ems3 = last_item; });
    timed_event(14000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1648754951227,  -86.78355664014816), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(14002*coefficient, function() { window.ems2 = last_item; });
    timed_event(15000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164871164308664,  -86.78363710641861), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(15002*coefficient, function() { window.ems1 = last_item; });
    timed_event(23000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16476289388051,  -86.78346008062362), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(23002*coefficient, function() { window.ems6 = last_item; });
    timed_event(24000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16474557059812,  -86.78356200456619), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(24002*coefficient, function() { window.ems5 = last_item; });
    timed_event(27000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164674112017835,  -86.78346276283264), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(27002*coefficient, function() { window.ems7 = last_item; });
    timed_event(33000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164604818786834,  -86.78337961435318), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(33002*coefficient, function() { window.ems8 = last_item; });
    timed_event(38000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16462647292811,  -86.78330719470978), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(38002*coefficient, function() { window.ems9 = last_item; });
    timed_event(39000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16464596165013,  -86.78321063518524), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(39002*coefficient, function() { window.ems10 = last_item; });
    timed_event(45000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644575704676,  -86.78339302539825), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(45002*coefficient, function() { window.ems13 = last_item; });
    timed_event(46000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16445323963048,  -86.7835083603859), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(46002*coefficient, function() { window.ems12 = last_item; });
    timed_event(49000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164539856327146,  -86.783167719841), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(49002*coefficient, function() { window.ems11 = last_item; });
    timed_event(53000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644640667228,  -86.78324550390243), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(53002*coefficient, function() { window.ems14 = last_item; });
    timed_event(54000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16438611162475,  -86.78330987691879), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(54002*coefficient, function() { window.ems15 = last_item; });
    timed_event(54005*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16436662283812,  -86.7832562327385), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(54007*coefficient, function() { window.ems16 = last_item; });
    timed_event(59000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16429083306628,  -86.78318113088608), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(59002*coefficient, function() { window.ems17 = last_item; });
    timed_event(64000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16421287779595,  -86.78319722414017), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(64002*coefficient, function() { window.ems19 = last_item; });
    timed_event(68000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164195554392016,  -86.78305774927139), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(68002*coefficient, function() { window.ems20 = last_item; });
    timed_event(70000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16435796115361,  -86.78290218114853), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(70002*coefficient, function() { window.ems18 = last_item; });
    timed_event(70005*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164267013408576,  -86.78286999464035), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(70007*coefficient, function() { window.ems21 = last_item; });
    timed_event(75000*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16404180901432,  -86.78310066461563), 'images/victimtriagelevelunknownunknown.png', 0)); });
    timed_event(75002*coefficient, function() { window.ems22 = last_item; });

    //Delete normal victims
    timed_event(26019*coefficient, function() { trigger(map, 'delete_item', ems4); });
    timed_event(27019*coefficient, function() { trigger(map, 'delete_item', ems3); });
    timed_event(29019*coefficient, function() { trigger(map, 'delete_item', ems2); });
    timed_event(30019*coefficient, function() { trigger(map, 'delete_item', ems1); });
    timed_event(38019*coefficient, function() { trigger(map, 'delete_item', ems6); });
    timed_event(39019*coefficient, function() { trigger(map, 'delete_item', ems5); });
    timed_event(42019*coefficient, function() { trigger(map, 'delete_item', ems7); });
    timed_event(48019*coefficient, function() { trigger(map, 'delete_item', ems8); });
    timed_event(53019*coefficient, function() { trigger(map, 'delete_item', ems9); });
    timed_event(54019*coefficient, function() { trigger(map, 'delete_item', ems10); });
    timed_event(60019*coefficient, function() { trigger(map, 'delete_item', ems13); });
    timed_event(61019*coefficient, function() { trigger(map, 'delete_item', ems12); });
    timed_event(64019*coefficient, function() { trigger(map, 'delete_item', ems11); });
    timed_event(68019*coefficient, function() { trigger(map, 'delete_item', ems14); });
    timed_event(69019*coefficient, function() { trigger(map, 'delete_item', ems15); });
    timed_event(69024*coefficient, function() { trigger(map, 'delete_item', ems16); });
    timed_event(74019*coefficient, function() { trigger(map, 'delete_item', ems17); });
    timed_event(79019*coefficient, function() { trigger(map, 'delete_item', ems19); });
    timed_event(83019*coefficient, function() { trigger(map, 'delete_item', ems20); });
    timed_event(85019*coefficient, function() { trigger(map, 'delete_item', ems18); });
    timed_event(85024*coefficient, function() { trigger(map, 'delete_item', ems21); });
    timed_event(90019*coefficient, function() { trigger(map, 'delete_item', ems22); });

    //Create residue victims
    timed_event(26020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16499242701067,  -86.78335279226303), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(26022*coefficient, function() { window.ems4 = last_item; });
    timed_event(27020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164940457304226,  -86.78347617387771), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(27022*coefficient, function() { window.ems3 = last_item; });
    timed_event(29020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1648754951227,  -86.78355664014816), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(29022*coefficient, function() { window.ems2 = last_item; });
    timed_event(30020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164871164308664,  -86.78363710641861), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(30022*coefficient, function() { window.ems1 = last_item; });
    timed_event(38020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16476289388051,  -86.78346008062362), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(38022*coefficient, function() { window.ems6 = last_item; });
    timed_event(39020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16474557059812,  -86.78356200456619), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(39022*coefficient, function() { window.ems5 = last_item; });
    timed_event(42020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164674112017835,  -86.78346276283264), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(42022*coefficient, function() { window.ems7 = last_item; });
    timed_event(48020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164604818786834,  -86.78337961435318), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(48022*coefficient, function() { window.ems8 = last_item; });
    timed_event(53020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16462647292811,  -86.78330719470978), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(53022*coefficient, function() { window.ems9 = last_item; });
    timed_event(54020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16464596165013,  -86.78321063518524), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(54022*coefficient, function() { window.ems10 = last_item; });
    timed_event(60020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644575704676,  -86.78339302539825), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(60022*coefficient, function() { window.ems13 = last_item; });
    timed_event(61020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16445323963048,  -86.7835083603859), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(61022*coefficient, function() { window.ems12 = last_item; });
    timed_event(64020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164539856327146,  -86.783167719841), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(64022*coefficient, function() { window.ems11 = last_item; });
    timed_event(68020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644640667228,  -86.78324550390243), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(68022*coefficient, function() { window.ems14 = last_item; });
    timed_event(69020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16438611162475,  -86.78330987691879), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(69022*coefficient, function() { window.ems15 = last_item; });
    timed_event(69025*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16436662283812,  -86.7832562327385), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(69027*coefficient, function() { window.ems16 = last_item; });
    timed_event(74020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16429083306628,  -86.78318113088608), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(74022*coefficient, function() { window.ems17 = last_item; });
    timed_event(79020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16421287779595,  -86.78319722414017), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(79022*coefficient, function() { window.ems19 = last_item; });
    timed_event(83020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164195554392016,  -86.78305774927139), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(83022*coefficient, function() { window.ems20 = last_item; });
    timed_event(85020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16435796115361,  -86.78290218114853), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(85022*coefficient, function() { window.ems18 = last_item; });
    timed_event(85025*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164267013408576,  -86.78286999464035), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(85027*coefficient, function() { window.ems21 = last_item; });
    timed_event(90020*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16404180901432,  -86.78310066461563), 'images/victimtriagelevelunknownunknownRes.png', 0)); });
    timed_event(90022*coefficient, function() { window.ems22 = last_item; });

    //Delete residue victims
    timed_event(59024*coefficient, function() { trigger(map, 'delete_item', ems4); });
    timed_event(59029*coefficient, function() { trigger(map, 'delete_item', ems3); });
    timed_event(59034*coefficient, function() { trigger(map, 'delete_item', ems2); });
    timed_event(59039*coefficient, function() { trigger(map, 'delete_item', ems1); });
    timed_event(59044*coefficient, function() { trigger(map, 'delete_item', ems6); });
    timed_event(59049*coefficient, function() { trigger(map, 'delete_item', ems5); });
    timed_event(59054*coefficient, function() { trigger(map, 'delete_item', ems7); });
    timed_event(59059*coefficient, function() { trigger(map, 'delete_item', ems8); });
    timed_event(59064*coefficient, function() { trigger(map, 'delete_item', ems9); });
    timed_event(59069*coefficient, function() { trigger(map, 'delete_item', ems10); });
    timed_event(73024*coefficient, function() { trigger(map, 'delete_item', ems13); });
    timed_event(73029*coefficient, function() { trigger(map, 'delete_item', ems12); });
    timed_event(73034*coefficient, function() { trigger(map, 'delete_item', ems11); });
    timed_event(73039*coefficient, function() { trigger(map, 'delete_item', ems14); });
    timed_event(73044*coefficient, function() { trigger(map, 'delete_item', ems15); });
    timed_event(73049*coefficient, function() { trigger(map, 'delete_item', ems16); });
    timed_event(95024*coefficient, function() { trigger(map, 'delete_item', ems17); });
    timed_event(95029*coefficient, function() { trigger(map, 'delete_item', ems19); });
    timed_event(95034*coefficient, function() { trigger(map, 'delete_item', ems20); });
    timed_event(95039*coefficient, function() { trigger(map, 'delete_item', ems18); });
    timed_event(95044*coefficient, function() { trigger(map, 'delete_item', ems21); });
    timed_event(95049*coefficient, function() { trigger(map, 'delete_item', ems22); });

    //Create grouped victims
    timed_event(59025*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16499242701067,  -86.78335279226303), 'images/grouped.png', 0)); });
    timed_event(59027*coefficient, function() { window.ems4 = last_item; });
    timed_event(59030*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164940457304226,  -86.78347617387771), 'images/grouped.png', 0)); });
    timed_event(59032*coefficient, function() { window.ems3 = last_item; });
    timed_event(59035*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1648754951227,  -86.78355664014816), 'images/grouped.png', 0)); });
    timed_event(59037*coefficient, function() { window.ems2 = last_item; });
    timed_event(59040*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164871164308664,  -86.78363710641861), 'images/grouped.png', 0)); });
    timed_event(59042*coefficient, function() { window.ems1 = last_item; });
    timed_event(59045*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16476289388051,  -86.78346008062362), 'images/grouped.png', 0)); });
    timed_event(59047*coefficient, function() { window.ems6 = last_item; });
    timed_event(59050*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16474557059812,  -86.78356200456619), 'images/grouped.png', 0)); });
    timed_event(59052*coefficient, function() { window.ems5 = last_item; });
    timed_event(59055*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164674112017835,  -86.78346276283264), 'images/grouped.png', 0)); });
    timed_event(59057*coefficient, function() { window.ems7 = last_item; });
    timed_event(59060*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164604818786834,  -86.78337961435318), 'images/grouped.png', 0)); });
    timed_event(59062*coefficient, function() { window.ems8 = last_item; });
    timed_event(59065*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16462647292811,  -86.78330719470978), 'images/grouped.png', 0)); });
    timed_event(59067*coefficient, function() { window.ems9 = last_item; });
    timed_event(59070*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16464596165013,  -86.78321063518524), 'images/grouped.png', 0)); });
    timed_event(59072*coefficient, function() { window.ems10 = last_item; });
    timed_event(73025*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644575704676,  -86.78339302539825), 'images/grouped.png', 0)); });
    timed_event(73027*coefficient, function() { window.ems13 = last_item; });
    timed_event(73030*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16445323963048,  -86.7835083603859), 'images/grouped.png', 0)); });
    timed_event(73032*coefficient, function() { window.ems12 = last_item; });
    timed_event(73035*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164539856327146,  -86.783167719841), 'images/grouped.png', 0)); });
    timed_event(73037*coefficient, function() { window.ems11 = last_item; });
    timed_event(73040*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.1644640667228,  -86.78324550390243), 'images/grouped.png', 0)); });
    timed_event(73042*coefficient, function() { window.ems14 = last_item; });
    timed_event(73045*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16438611162475,  -86.78330987691879), 'images/grouped.png', 0)); });
    timed_event(73047*coefficient, function() { window.ems15 = last_item; });
    timed_event(73050*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16436662283812,  -86.7832562327385), 'images/grouped.png', 0)); });
    timed_event(73052*coefficient, function() { window.ems16 = last_item; });
    timed_event(95025*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16429083306628,  -86.78318113088608), 'images/grouped.png', 0)); });
    timed_event(95027*coefficient, function() { window.ems17 = last_item; });
    timed_event(95030*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16421287779595,  -86.78319722414017), 'images/grouped.png', 0)); });
    timed_event(95032*coefficient, function() { window.ems19 = last_item; });
    timed_event(95035*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164195554392016,  -86.78305774927139), 'images/grouped.png', 0)); });
    timed_event(95037*coefficient, function() { window.ems20 = last_item; });
    timed_event(95040*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16435796115361,  -86.78290218114853), 'images/grouped.png', 0)); });
    timed_event(95042*coefficient, function() { window.ems18 = last_item; });
    timed_event(95045*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.164267013408576,  -86.78286999464035), 'images/grouped.png', 0)); });
    timed_event(95047*coefficient, function() { window.ems21 = last_item; });
    timed_event(95050*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng (36.16404180901432,  -86.78310066461563), 'images/grouped.png', 0)); });
    timed_event(95052*coefficient, function() { window.ems22 = last_item; });

    //Create normal readings
    timed_event(15500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16490148000173,  -86.78424596786499), 'images/HAZMATReading.png', 0)); });
    timed_event(15502*coefficient, function() { window.hazmat1 = last_item; });
    timed_event(17500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164834352379856,  -86.78418159484863), 'images/HAZMATReading.png', 0)); });
    timed_event(17502*coefficient, function() { window.hazmat2 = last_item; });
    timed_event(40500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164940457304205,  -86.78414672613144), 'images/HAZMATReading.png', 0)); });
    timed_event(40502*coefficient, function() { window.hazmat3 = last_item; });
    timed_event(42500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164884156749984,  -86.78409039974212), 'images/HAZMATReading.png', 0)); });
    timed_event(42502*coefficient, function() { window.hazmat4 = last_item; });
    timed_event(65500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16498593079923,  -86.78400993347168), 'images/HAZMATReading.png', 0)); });
    timed_event(65502*coefficient, function() { window.hazmat5 = last_item; });
    timed_event(67500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164944788114376,  -86.78392946720123), 'images/HAZMATReading.png', 0)); });
    timed_event(67502*coefficient, function() { window.hazmat6 = last_item; });
    timed_event(90500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16502490805969,  -86.78390800952911), 'images/HAZMATReading.png', 0)); });
    timed_event(90502*coefficient, function() { window.hazmat7 = last_item; });
    timed_event(92500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16500541943189,  -86.78380608558655), 'images/HAZMATReading.png', 0)); });
    timed_event(92502*coefficient, function() { window.hazmat8 = last_item; });
    timed_event(115500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507254690726,  -86.78380876779556), 'images/HAZMATReading.png', 0)); });
    timed_event(115502*coefficient, function() { window.hazmat9 = last_item; });
    timed_event(117500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165131012726086,  -86.78369075059891), 'images/HAZMATReading.png', 0)); });
    timed_event(117502*coefficient, function() { window.hazmat10 = last_item; });
    timed_event(140500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.78366661071777), 'images/HAZMATReading.png', 0)); });
    timed_event(140502*coefficient, function() { window.hazmat11 = last_item; });
    timed_event(142500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.78355932235718), 'images/HAZMATReading.png', 0)); });
    timed_event(142502*coefficient, function() { window.hazmat12 = last_item; });
    timed_event(165500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16512235112605,  -86.78351640701294), 'images/HAZMATReading.png', 0)); });
    timed_event(165502*coefficient, function() { window.hazmat13 = last_item; });
    timed_event(167500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78345203399658), 'images/HAZMATReading.png', 0)); });
    timed_event(167502*coefficient, function() { window.hazmat14 = last_item; });
    timed_event(190500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.7834010720253), 'images/HAZMATReading.png', 0)); });
    timed_event(190502*coefficient, function() { window.hazmat15 = last_item; });
    timed_event(192500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.78330451250076), 'images/HAZMATReading.png', 0)); });
    timed_event(192502*coefficient, function() { window.hazmat16 = last_item; });
    timed_event(215500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78326427936554), 'images/HAZMATReading.png', 0)); });
    timed_event(215502*coefficient, function() { window.hazmat17 = last_item; });
    timed_event(50500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16535188320363,  -86.78315162658691), 'images/HAZMATReading.png', 0)); });
    timed_event(50502*coefficient, function() { window.hazmat18 = last_item; });
    timed_event(51700*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16526093661178,  -86.78318113088608), 'images/HAZMATReading.png', 0)); });
    timed_event(51702*coefficient, function() { window.hazmat19 = last_item; });
    timed_event(65500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.7831140756607), 'images/HAZMATReading.png', 0)); });
    timed_event(65502*coefficient, function() { window.hazmat20 = last_item; });
    timed_event(66700*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165172155313186,  -86.78311139345169), 'images/HAZMATReading.png', 0)); });
    timed_event(66702*coefficient, function() { window.hazmat21 = last_item; });
    timed_event(80500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16521979407126,  -86.78304702043533), 'images/HAZMATReading.png', 0)); });
    timed_event(80502*coefficient, function() { window.hazmat22 = last_item; });
    timed_event(81700*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16506821610414,  -86.78294241428375), 'images/HAZMATReading.png', 0)); });
    timed_event(81702*coefficient, function() { window.hazmat23 = last_item; });
    timed_event(95500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165152666722,  -86.78300142288208), 'images/HAZMATReading.png', 0)); });
    timed_event(95502*coefficient, function() { window.hazmat24 = last_item; });
    timed_event(96700*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.7830416560173), 'images/HAZMATReading.png', 0)); });
    timed_event(96702*coefficient, function() { window.hazmat25 = last_item; });
    timed_event(110500*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165003254028484,  -86.78299069404602), 'images/HAZMATReading.png', 0)); });
    timed_event(110502*coefficient, function() { window.hazmat26 = last_item; });
    timed_event(111700*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16495128432922,  -86.78291022777557), 'images/HAZMATReading.png', 0)); });
    timed_event(111702*coefficient, function() { window.hazmat27 = last_item; });

    //Delete normal readings
    timed_event(30519*coefficient, function() { trigger(map, 'delete_item', hazmat1); });
    timed_event(32519*coefficient, function() { trigger(map, 'delete_item', hazmat2); });
    timed_event(55519*coefficient, function() { trigger(map, 'delete_item', hazmat3); });
    timed_event(57519*coefficient, function() { trigger(map, 'delete_item', hazmat4); });
    timed_event(80519*coefficient, function() { trigger(map, 'delete_item', hazmat5); });
    timed_event(82519*coefficient, function() { trigger(map, 'delete_item', hazmat6); });
    timed_event(105519*coefficient, function() { trigger(map, 'delete_item', hazmat7); });
    timed_event(107519*coefficient, function() { trigger(map, 'delete_item', hazmat8); });
    timed_event(130519*coefficient, function() { trigger(map, 'delete_item', hazmat9); });
    timed_event(132519*coefficient, function() { trigger(map, 'delete_item', hazmat10); });
    timed_event(155519*coefficient, function() { trigger(map, 'delete_item', hazmat11); });
    timed_event(157519*coefficient, function() { trigger(map, 'delete_item', hazmat12); });
    timed_event(180519*coefficient, function() { trigger(map, 'delete_item', hazmat13); });
    timed_event(182519*coefficient, function() { trigger(map, 'delete_item', hazmat14); });
    timed_event(205519*coefficient, function() { trigger(map, 'delete_item', hazmat15); });
    timed_event(207519*coefficient, function() { trigger(map, 'delete_item', hazmat16); });
    timed_event(230519*coefficient, function() { trigger(map, 'delete_item', hazmat17); });
    timed_event(65519*coefficient, function() { trigger(map, 'delete_item', hazmat18); });
    timed_event(66719*coefficient, function() { trigger(map, 'delete_item', hazmat19); });
    timed_event(80519*coefficient, function() { trigger(map, 'delete_item', hazmat20); });
    timed_event(81719*coefficient, function() { trigger(map, 'delete_item', hazmat21); });
    timed_event(95519*coefficient, function() { trigger(map, 'delete_item', hazmat22); });
    timed_event(96719*coefficient, function() { trigger(map, 'delete_item', hazmat23); });
    timed_event(110519*coefficient, function() { trigger(map, 'delete_item', hazmat24); });
    timed_event(111719*coefficient, function() { trigger(map, 'delete_item', hazmat25); });
    timed_event(125519*coefficient, function() { trigger(map, 'delete_item', hazmat26); });
    timed_event(126719*coefficient, function() { trigger(map, 'delete_item', hazmat27); });

    //Create residue readings
    timed_event(30520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16490148000173,  -86.78424596786499), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(30522*coefficient, function() { window.hazmat1 = last_item; });
    timed_event(32520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164834352379856,  -86.78418159484863), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(32522*coefficient, function() { window.hazmat2 = last_item; });
    timed_event(55520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164940457304205,  -86.78414672613144), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(55522*coefficient, function() { window.hazmat3 = last_item; });
    timed_event(57520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164884156749984,  -86.78409039974212), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(57522*coefficient, function() { window.hazmat4 = last_item; });
    timed_event(80520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16498593079923,  -86.78400993347168), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(80522*coefficient, function() { window.hazmat5 = last_item; });
    timed_event(82520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164944788114376,  -86.78392946720123), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(82522*coefficient, function() { window.hazmat6 = last_item; });
    timed_event(105520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16502490805969,  -86.78390800952911), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(105522*coefficient, function() { window.hazmat7 = last_item; });
    timed_event(107520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16500541943189,  -86.78380608558655), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(107522*coefficient, function() { window.hazmat8 = last_item; });
    timed_event(130520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507254690726,  -86.78380876779556), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(130522*coefficient, function() { window.hazmat9 = last_item; });
    timed_event(132520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165131012726086,  -86.78369075059891), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(132522*coefficient, function() { window.hazmat10 = last_item; });
    timed_event(155520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.78366661071777), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(155522*coefficient, function() { window.hazmat11 = last_item; });
    timed_event(157520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.78355932235718), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(157522*coefficient, function() { window.hazmat12 = last_item; });
    timed_event(180520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16512235112605,  -86.78351640701294), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(180522*coefficient, function() { window.hazmat13 = last_item; });
    timed_event(182520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78345203399658), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(182522*coefficient, function() { window.hazmat14 = last_item; });
    timed_event(205520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.7834010720253), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(205522*coefficient, function() { window.hazmat15 = last_item; });
    timed_event(207520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.78330451250076), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(207522*coefficient, function() { window.hazmat16 = last_item; });
    timed_event(230520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78326427936554), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(230522*coefficient, function() { window.hazmat17 = last_item; });
    timed_event(65520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16535188320363,  -86.78315162658691), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(65522*coefficient, function() { window.hazmat18 = last_item; });
    timed_event(66720*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16526093661178,  -86.78318113088608), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(66722*coefficient, function() { window.hazmat19 = last_item; });
    timed_event(80520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.7831140756607), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(80522*coefficient, function() { window.hazmat20 = last_item; });
    timed_event(81720*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165172155313186,  -86.78311139345169), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(81722*coefficient, function() { window.hazmat21 = last_item; });
    timed_event(95520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16521979407126,  -86.78304702043533), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(95522*coefficient, function() { window.hazmat22 = last_item; });
    timed_event(96720*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16506821610414,  -86.78294241428375), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(96722*coefficient, function() { window.hazmat23 = last_item; });
    timed_event(110520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165152666722,  -86.78300142288208), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(110522*coefficient, function() { window.hazmat24 = last_item; });
    timed_event(111720*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.7830416560173), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(111722*coefficient, function() { window.hazmat25 = last_item; });
    timed_event(125520*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165003254028484,  -86.78299069404602), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(125522*coefficient, function() { window.hazmat26 = last_item; });
    timed_event(126720*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16495128432922,  -86.78291022777557), 'images/HAZMATReadingRes.png', 0)); });
    timed_event(126722*coefficient, function() { window.hazmat27 = last_item; });

    //Delete residue readings
    timed_event(112524*coefficient, function() { trigger(map, 'delete_item', hazmat1); });
    timed_event(112529*coefficient, function() { trigger(map, 'delete_item', hazmat2); });
    timed_event(112534*coefficient, function() { trigger(map, 'delete_item', hazmat3); });
    timed_event(112539*coefficient, function() { trigger(map, 'delete_item', hazmat4); });
    timed_event(112544*coefficient, function() { trigger(map, 'delete_item', hazmat5); });
    timed_event(112549*coefficient, function() { trigger(map, 'delete_item', hazmat6); });
    timed_event(112554*coefficient, function() { trigger(map, 'delete_item', hazmat7); });
    timed_event(112559*coefficient, function() { trigger(map, 'delete_item', hazmat8); });
    timed_event(235524*coefficient, function() { trigger(map, 'delete_item', hazmat9); });
    timed_event(235529*coefficient, function() { trigger(map, 'delete_item', hazmat10); });
    timed_event(235534*coefficient, function() { trigger(map, 'delete_item', hazmat11); });
    timed_event(235539*coefficient, function() { trigger(map, 'delete_item', hazmat12); });
    timed_event(235544*coefficient, function() { trigger(map, 'delete_item', hazmat13); });
    timed_event(235549*coefficient, function() { trigger(map, 'delete_item', hazmat14); });
    timed_event(235554*coefficient, function() { trigger(map, 'delete_item', hazmat15); });
    timed_event(235559*coefficient, function() { trigger(map, 'delete_item', hazmat16); });
    timed_event(235564*coefficient, function() { trigger(map, 'delete_item', hazmat17); });
    timed_event(131724*coefficient, function() { trigger(map, 'delete_item', hazmat18); });
    timed_event(131729*coefficient, function() { trigger(map, 'delete_item', hazmat19); });
    timed_event(131734*coefficient, function() { trigger(map, 'delete_item', hazmat20); });
    timed_event(131739*coefficient, function() { trigger(map, 'delete_item', hazmat21); });
    timed_event(131744*coefficient, function() { trigger(map, 'delete_item', hazmat22); });
    timed_event(131749*coefficient, function() { trigger(map, 'delete_item', hazmat23); });
    timed_event(131754*coefficient, function() { trigger(map, 'delete_item', hazmat24); });
    timed_event(131759*coefficient, function() { trigger(map, 'delete_item', hazmat25); });
    timed_event(131764*coefficient, function() { trigger(map, 'delete_item', hazmat26); });
    timed_event(131769*coefficient, function() { trigger(map, 'delete_item', hazmat27); });

    //Create grouped readings
    timed_event(112525*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16490148000173,  -86.78424596786499), 'images/grouped.png', 0)); });
    timed_event(112527*coefficient, function() { window.hazmat1 = last_item; });
    timed_event(112530*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164834352379856,  -86.78418159484863), 'images/grouped.png', 0)); });
    timed_event(112532*coefficient, function() { window.hazmat2 = last_item; });
    timed_event(112535*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164940457304205,  -86.78414672613144), 'images/grouped.png', 0)); });
    timed_event(112537*coefficient, function() { window.hazmat3 = last_item; });
    timed_event(112540*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164884156749984,  -86.78409039974212), 'images/grouped.png', 0)); });
    timed_event(112542*coefficient, function() { window.hazmat4 = last_item; });
    timed_event(112545*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16498593079923,  -86.78400993347168), 'images/grouped.png', 0)); });
    timed_event(112547*coefficient, function() { window.hazmat5 = last_item; });
    timed_event(112550*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164944788114376,  -86.78392946720123), 'images/grouped.png', 0)); });
    timed_event(112552*coefficient, function() { window.hazmat6 = last_item; });
    timed_event(112555*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16502490805969,  -86.78390800952911), 'images/grouped.png', 0)); });
    timed_event(112557*coefficient, function() { window.hazmat7 = last_item; });
    timed_event(112560*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16500541943189,  -86.78380608558655), 'images/grouped.png', 0)); });
    timed_event(112562*coefficient, function() { window.hazmat8 = last_item; });
    timed_event(235525*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507254690726,  -86.78380876779556), 'images/grouped.png', 0)); });
    timed_event(235527*coefficient, function() { window.hazmat9 = last_item; });
    timed_event(235530*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165131012726086,  -86.78369075059891), 'images/grouped.png', 0)); });
    timed_event(235532*coefficient, function() { window.hazmat10 = last_item; });
    timed_event(235535*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.78366661071777), 'images/grouped.png', 0)); });
    timed_event(235537*coefficient, function() { window.hazmat11 = last_item; });
    timed_event(235540*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.78355932235718), 'images/grouped.png', 0)); });
    timed_event(235542*coefficient, function() { window.hazmat12 = last_item; });
    timed_event(235545*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16512235112605,  -86.78351640701294), 'images/grouped.png', 0)); });
    timed_event(235547*coefficient, function() { window.hazmat13 = last_item; });
    timed_event(235550*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78345203399658), 'images/grouped.png', 0)); });
    timed_event(235552*coefficient, function() { window.hazmat14 = last_item; });
    timed_event(235555*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16518081690772,  -86.7834010720253), 'images/grouped.png', 0)); });
    timed_event(235557*coefficient, function() { window.hazmat15 = last_item; });
    timed_event(235560*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.78330451250076), 'images/grouped.png', 0)); });
    timed_event(235562*coefficient, function() { window.hazmat16 = last_item; });
    timed_event(235565*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16523711724884,  -86.78326427936554), 'images/grouped.png', 0)); });
    timed_event(235567*coefficient, function() { window.hazmat17 = last_item; });
    timed_event(131725*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16535188320363,  -86.78315162658691), 'images/grouped.png', 0)); });
    timed_event(131727*coefficient, function() { window.hazmat18 = last_item; });
    timed_event(131730*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16526093661178,  -86.78318113088608), 'images/grouped.png', 0)); });
    timed_event(131732*coefficient, function() { window.hazmat19 = last_item; });
    timed_event(131735*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165293417549556,  -86.7831140756607), 'images/grouped.png', 0)); });
    timed_event(131737*coefficient, function() { window.hazmat20 = last_item; });
    timed_event(131740*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165172155313186,  -86.78311139345169), 'images/grouped.png', 0)); });
    timed_event(131742*coefficient, function() { window.hazmat21 = last_item; });
    timed_event(131745*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16521979407126,  -86.78304702043533), 'images/grouped.png', 0)); });
    timed_event(131747*coefficient, function() { window.hazmat22 = last_item; });
    timed_event(131750*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16506821610414,  -86.78294241428375), 'images/grouped.png', 0)); });
    timed_event(131752*coefficient, function() { window.hazmat23 = last_item; });
    timed_event(131755*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165152666722,  -86.78300142288208), 'images/grouped.png', 0)); });
    timed_event(131757*coefficient, function() { window.hazmat24 = last_item; });
    timed_event(131760*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16507471230873,  -86.7830416560173), 'images/grouped.png', 0)); });
    timed_event(131762*coefficient, function() { window.hazmat25 = last_item; });
    timed_event(131765*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.165003254028484,  -86.78299069404602), 'images/grouped.png', 0)); });
    timed_event(131767*coefficient, function() { window.hazmat26 = last_item; });
    timed_event(131770*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16495128432922,  -86.78291022777557), 'images/grouped.png', 0)); });
    timed_event(131772*coefficient, function() { window.hazmat27 = last_item; });

    //hazmat_5 & _6 move around
    timed_event(6000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16490148000173,  -86.78424596786499)); });
    timed_event(7000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164834352379856,  -86.78418159484863)); });
    timed_event(17000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.164940457304205,  -86.78414672613144)); });
    timed_event(19000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164884156749984,  -86.78409039974212)); });
    timed_event(42000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16498593079923,  -86.78400993347168)); });
    timed_event(44000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164944788114376,  -86.78392946720123)); });
    timed_event(67000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16502490805969,  -86.78390800952911)); });
    timed_event(69000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16500541943189,  -86.78380608558655)); });
    timed_event(92000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16507254690726,  -86.78380876779556)); });
    timed_event(94000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.165131012726086,  -86.78369075059891)); });
    timed_event(117000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16507471230873,  -86.78366661071777)); });
    timed_event(119000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16518081690772,  -86.78355932235718)); });
    timed_event(142000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16512235112605,  -86.78351640701294)); });
    timed_event(144000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.16523711724884,  -86.78345203399658)); });
    timed_event(167000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16518081690772,  -86.7834010720253)); });
    timed_event(169000*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.165293417549556,  -86.78330451250076)); });
    timed_event(192000*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16523711724884,  -86.78326427936554)); });

    //hazmat_3 & _4 move around
    timed_event(194000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16494669366483, -86.78284853696823)); });
    timed_event(217000*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16490771636549, -86.78291827440262)); });
    timed_event(52000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165293417549556,  -86.7831140756607)); });
    timed_event(53200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.165172155313186,  -86.78311139345169)); });
    timed_event(67000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16521979407126,  -86.78304702043533)); });
    timed_event(68200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16506821610414,  -86.78294241428375)); });
    timed_event(82000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165152666722,  -86.78300142288208)); });
    timed_event(83200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16507471230873,  -86.7830416560173)); });
    timed_event(97000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.165003254028484,  -86.78299069404602)); });
    timed_event(98200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16495128432922,  -86.78291022777557)); });
    timed_event(30000*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16534408778476, -86.78323209285736)); });
    timed_event(30000*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16530727607808, -86.78321868181228)); });

    //ems_1
    timed_event(6000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16503114441775, -86.7833286523819)); });
    timed_event(11000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16481027303645, -86.78366124629974)); });
    timed_event(16000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16491854339916, -86.78325086832046)); });
    timed_event(21000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164704167935895, -86.78357809782028)); });
    timed_event(26000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16478645353657, -86.78317040205002)); });
    timed_event(31000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164530934809996, -86.78357005119324)); });
    timed_event(36000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16466302510316, -86.78308725357055)); });
    timed_event(41000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16443782184663, -86.78347885608673)); });
    timed_event(46000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164587235617894, -86.7830416560173)); });
    timed_event(51000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16432738539786, -86.78335547447204)); });
    timed_event(56000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16444648352228, -86.7829504609108)); });
    timed_event(61000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16414982058538, -86.78324550390243)); });
    timed_event(66000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164277580673975, -86.78283244371414)); });
    timed_event(71000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16401989485804, -86.78319990634918)); });
    timed_event(76000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16416497857288, -86.78275734186172)); });
    timed_event(91000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16410218117704, -86.78273320198059)); });
    timed_event(93000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16380335150054, -86.78355664014816)); });
    timed_event(104000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164015563996756, -86.78293973207474)); });
    timed_event(109000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1638336676066, -86.78302824497223)); });
    timed_event(114000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.163775200820154, -86.7833662033081)); });
    timed_event(119000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16371889942899, -86.78350567817688)); });
    timed_event(124000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.163595469314586, -86.7835083603859)); });
    timed_event(139000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164032887440456, -86.78245157003402)); });
    timed_event(150000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16417147485235, -86.78229331970215)); });
    timed_event(152500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16412600088482, -86.78255617618561)); });
    timed_event(155000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1642645881321, -86.78237110376358)); });
    timed_event(157500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16420395624157, -86.78258836269378)); });
    timed_event(160000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164316558286636, -86.78238987922668)); });
    timed_event(162500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.1642710844033, -86.78264200687408)); });
    timed_event(165000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16437719009009, -86.7824274301529)); });
    timed_event(167500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164318723709, -86.78267687559128)); });
    timed_event(170000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16443782184663, -86.7824649810791)); });
    timed_event(172500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16440317513434, -86.7827358841896)); });
    timed_event(175000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16464137097198, -86.78259640932083)); });
    timed_event(177500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16465003262517, -86.78289949893951)); });
    timed_event(180000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164788618945955, -86.78270906209945)); });
    timed_event(182500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16476263402947, -86.78297460079193)); });
    timed_event(185000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164883896899354, -86.78280025720596)); });
    timed_event(187500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.164873069865024, -86.78303360939026)); });
    timed_event(190000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16500082877481, -86.78285390138626)); });
    timed_event(192500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16496185150239, -86.7830953001976)); });
    timed_event(195000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16507878326153, -86.78290218114853)); });
    timed_event(197500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.165028979015084, -86.78314357995987)); });
    timed_event(200000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16518705325337, -86.7829692363739)); });
    timed_event(202500*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.165128587476346, -86.7832213640213)); });
    timed_event(205000*coefficient, function() { trigger(map, 'move_item', ems_1, new LatLng(36.16527583453509, -86.78304970264435)); });

    //ems_2
    timed_event(22000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165173021472754,  -86.78323745727539)); });
    timed_event(29000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16525097578823,  -86.78301483392715)); });
    timed_event(36000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165116721085575,  -86.78321063518524)); });
    timed_event(43000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16518384846566,  -86.78297191858291)); });
    timed_event(50000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16505392445218,  -86.78318917751312)); });
    timed_event(57000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16512321728617,  -86.78293168544769)); });
    timed_event(64000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16499762397949,  -86.78313821554184)); });
    timed_event(71000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.165073413067944,  -86.78289145231247)); });
    timed_event(78000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16491966941206,  -86.78307920694351)); });
    timed_event(85000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16498463155697,  -86.78281635046005)); });
    timed_event(92000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164861203435606,  -86.78304702043533)); });
    timed_event(99000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164947819681444,  -86.782805621624)); });
    timed_event(106000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164830887726936,  -86.78300946950912)); });
    timed_event(113000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164904511570484,  -86.78277611732483)); });
    timed_event(120000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16479624118838,  -86.78296387195587)); });
    timed_event(127000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16485254180575,  -86.78274393081665)); });
    timed_event(134000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.1647464367624,  -86.78291827440262)); });
    timed_event(141000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16480057200654,  -86.78270637989044)); });
    timed_event(148000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164687970656736,  -86.78288608789444)); });
    timed_event(155000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16476159463453,  -86.78267687559128)); });
    timed_event(162000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16462950450747,  -86.78284853696823)); });
    timed_event(169000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16470745936347,  -86.78263664245605)); });
    timed_event(176000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164623008265956,  -86.78284049034118)); });
    timed_event(183000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16468580524458,  -86.78263127803802)); });
    timed_event(190000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16456670748376,  -86.7828243970871)); });
    timed_event(197000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164648993228724,  -86.78261250257492)); });
    timed_event(204000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164425955351284,  -86.78276002407074)); });
    timed_event(211000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16449091790537,  -86.7825186252594)); });
    timed_event(218000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16437398526926,  -86.7826983332634)); });
    timed_event(225000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16441729367334,  -86.78247034549713)); });
    timed_event(232000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16429386465862,  -86.78265810012817)); });
    timed_event(239000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16436748900657,  -86.78243815898895)); });
    timed_event(246000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164237563640015,  -86.78262323141098)); });
    timed_event(253000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16432851141923,  -86.78240865468979)); });
    timed_event(260000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164213743966094,  -86.78259909152984)); });
    timed_event(267000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16428736838932,  -86.78237915039062)); });
    timed_event(274000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16420291683922,  -86.78258568048477)); });
    timed_event(281000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16426787957814,  -86.78235501050949)); });
    timed_event(288000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16417260087596,  -86.7825910449028)); });
    timed_event(295000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16425272161054,  -86.78233623504638)); });
    timed_event(302000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16414445032816,  -86.78258299827575)); });
    timed_event(309000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16422024024153,  -86.78232282400131)); });
    timed_event(316000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16411413434228,  -86.78256154060364)); });
    timed_event(323000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16418775885906,  -86.78229600191116)); });
    timed_event(330000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.164064329482926,  -86.78251594305038)); });
    timed_event(337000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16413145776422,  -86.78228259086609)); });
    timed_event(344000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16405350233539,  -86.78250521421432)); });
    timed_event(351000*coefficient, function() { trigger(map, 'move_item', ems_2, new LatLng(36.16456021123705,  -86.78329646587372)); });

    //ems_3
    timed_event(11500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16500732498088,  -86.78372293710708)); });
    timed_event(18500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16494019744963,  -86.7835459113121)); });
    timed_event(20500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16499242701067,  -86.78335279226303)); });
    timed_event(80500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16476289388051,  -86.78346008062362)); });
    timed_event(140500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.1646648873718,  -86.78337961435318)); });
    timed_event(143500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.16462647292811,  -86.78330719470978)); });
    timed_event(203500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng (36.164539856327146,  -86.783167719841)); });
    timed_event(263500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.164461338307554,  -86.7832562327385)); });
    timed_event(265500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng (36.16429083306628,  -86.78318113088608)); });
    timed_event(325500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng(36.164461338307554,  -86.7832562327385)); });
    timed_event(326500*coefficient, function() { trigger(map, 'move_item', ems_3, new LatLng (36.164267013408576,  -86.78286999464035)); });

    //ems_4
    timed_event(12500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng(36.1650463022307,  -86.78369343280792)); });
    timed_event(19500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng(36.16494019744963,  -86.7835459113121)); });
    timed_event(21500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.164940457304226,  -86.78347617387771)); });
    timed_event(81500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16474557059812,  -86.78356200456619)); });
    timed_event(141500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng(36.16465406030728,  -86.78335011005401)); });
    timed_event(143500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16464596165013,  -86.78321063518524)); });
    timed_event(203500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.1644640667228,  -86.78324550390243)); });
    timed_event(263500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16421287779595,  -86.78319722414017)); });
    timed_event(323500*coefficient, function() { trigger(map, 'move_item', ems_4, new LatLng (36.16404180901432,  -86.78310066461563)); });

    //ems_5
    timed_event(14500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng(36.16504413682844,  -86.78365588188171)); });
    timed_event(16500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng (36.1648754951227,  -86.78355664014816)); });
    timed_event(76500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng (36.164674112017835,  -86.78346276283264)); });
    timed_event(136500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng (36.1644575704676,  -86.78339302539825)); });
    timed_event(196500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng (36.16438611162475,  -86.78330987691879)); });
    timed_event(256500*coefficient, function() { trigger(map, 'move_item', ems_5, new LatLng (36.164195554392016,  -86.78305774927139)); });

    //ems_6
    timed_event(15500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng(36.16504413682844,  -86.78365588188171)); });
    timed_event(22500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng (36.164871164308664,  -86.78363710641861)); });
    timed_event(82500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng (36.164604818786834,  -86.78337961435318)); });
    timed_event(142500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16445323963048,  -86.7835083603859)); });
    timed_event(202500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16436662283812,  -86.7832562327385)); });
    timed_event(262500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng(36.164457007458786,  -86.78322404623031)); });
    timed_event(264500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng(36.16454362415128,  -86.7830228805542)); });
    timed_event(267500*coefficient, function() { trigger(map, 'move_item', ems_6, new LatLng (36.16435796115361,  -86.78290218114853)); });


//nevermind // End pasted in from excel

	timed_event(8090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16426138330668, -86.7828431725502), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(8092*coefficient, function() { window.suspObj5 = last_item; });
	timed_event(36090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(36092*coefficient, function() { window.suspObj3 = last_item; });
	timed_event(93090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164672812770384, -86.78213238716125), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(93092*coefficient, function() { window.suspObj7 = last_item; });
	timed_event(123090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486769965735, -86.7832401394844), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(123092*coefficient, function() { window.suspObj2 = last_item; });
	timed_event(288090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16513620968572, -86.78339302539825), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(288092*coefficient, function() { window.suspObj1 = last_item; });
	timed_event(297090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.163802312092876, -86.78354322910309), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(297092*coefficient, function() { window.suspObj6 = last_item; });
	timed_event(318090*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16398637398733, -86.78294509649277), 'images/classifyobjectuncertainsuspiciousitem.png', 20)); });
	timed_event(318092*coefficient, function() { window.suspObj4 = last_item; });

	timed_event(93190*coefficient, function() { trigger(map, 'delete_item', suspObj5); });
	timed_event(318190*coefficient, function() { trigger(map, 'delete_item', suspObj1); });
	timed_event(357190*coefficient, function() { trigger(map, 'delete_item', suspObj6); });

	//Suspicious Object 3 is a bomb
	timed_event(68619*coefficient, function() { trigger(map, 'delete_item', suspObj3); });
	timed_event(68620*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/suspiciousitem.png', 20)); });
	timed_event(68622*coefficient, function() { window.suspObj3 = last_item; });
    timed_event(69193*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.164379355506654, -86.78353250026703), 
         new google.maps.LatLng(36.16440967138995, -86.7834547162056), 
         new google.maps.LatLng(36.16435770129711, -86.7834198474884), 
         new google.maps.LatLng(36.16432088912719, -86.78348422050476)], affiliation.HAZMAT)); });
    timed_event(69194*coefficient, function() { window.hazmatTask3 = last_item; });
	timed_event(69194*coefficient, function() { hazmat_3.task = 'Classify Suspicious Object'; });


	timed_event(144200*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16472536010817, -86.78285390138626)); });
	timed_event(149200*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.16445251783528, -86.78329110145569)); });
	timed_event(151200*coefficient, function() { trigger(map, 'move_item', hazmat_3, new LatLng(36.164341503950496, -86.78346812725067)); });
	timed_event(211219*coefficient, function() { trigger(map, 'delete_item', suspObj3); });
	timed_event(211220*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164341503950496, -86.78346812725067), 'images/bomb.png', 40)); });
	timed_event(211222*coefficient, function() { window.suspObj3 = last_item; });

	//Suspicious Object 7 is found to be harmless
	timed_event(125619*coefficient, function() { trigger(map, 'delete_item', suspObj7); });
	timed_event(125620*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.164672812770384, -86.78213238716125), 'images/suspiciousitem.png', 20)); });
	timed_event(125622*coefficient, function() { window.suspObj7 = last_item; });
    timed_event(126193*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16470200252005, -86.78218334913254), 
         new google.maps.LatLng(36.16473015286763, -86.78211361169815), 
         new google.maps.LatLng(36.164680348399635, -86.78208410739898), 
         new google.maps.LatLng(36.16466085968619, -86.7821404337883)], affiliation.HAZMAT)); });
    timed_event(126194*coefficient, function() { window.hazmatTask4 = last_item; });
	timed_event(160200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16477296302341, -86.78277343511581)); });
	timed_event(162200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.1648379252899, -86.78246229887009)); });
	timed_event(165200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.164792451709026, -86.78237646818161)); });
	timed_event(167200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.16484225610577, -86.78224235773087)); });
	timed_event(169200*coefficient, function() { trigger(map, 'move_item', hazmat_4, new LatLng(36.164672812770384, -86.78213238716125)); });
	timed_event(229219*coefficient, function() { trigger(map, 'delete_item', suspObj7); });
	timed_event(229220*coefficient, function() { trigger(map, 'delete_item', hazmatTask4); });

	//Suspicious Object 2 is a bomb
	timed_event(155619*coefficient, function() { trigger(map, 'delete_item', suspObj2); });
	timed_event(155620*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486224282507, -86.78327232599258), 'images/suspiciousitem.png', 20)); });
	timed_event(155622*coefficient, function() { window.suspObj2 = last_item; });
    timed_event(156193*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16483625793713, -86.78317844867706), 
         new google.maps.LatLng(36.16482110007946, -86.78323209285736), 
         new google.maps.LatLng(36.16490988177564, -86.7832937836647), 
         new google.maps.LatLng(36.164935866643326, -86.78321063518524)], affiliation.HAZMAT)); });
    timed_event(156194*coefficient, function() { window.hazmatTask5 = last_item; });
	timed_event(158200*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16505230038737, -86.78364515304565)); });
	timed_event(163200*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16490072209634, -86.78351372480392)); });
	timed_event(166200*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.164987338298545, -86.78332328796387)); });
	timed_event(168200*coefficient, function() { trigger(map, 'move_item', hazmat_5, new LatLng(36.16492890848688, -86.78328305482864)); });
	timed_event(229219*coefficient, function() { trigger(map, 'delete_item', suspObj2); });
	timed_event(229220*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.16486224282507, -86.78327232599258), 'images/bomb.png', 40)); });
	timed_event(229222*coefficient, function() { window.suspObj2 = last_item; });
  
	timed_event(326619*coefficient, function() { trigger(map, 'delete_item', suspObj4); });
	timed_event(326620*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.1639852479569, -86.78297191858291), 'images/suspiciousitem.png', 20)); });
	timed_event(326622*coefficient, function() { window.suspObj4 = last_item; });
    timed_event(327193*coefficient, function() { trigger(map, 'add_item', task_area, task_area_options_template(map,
        [new google.maps.LatLng(36.16404371459084, -86.78299605846405), 
         new google.maps.LatLng(36.164076600992345, -86.78293832184113), 
         new google.maps.LatLng(36.16401989485804, -86.78287267684936), 
         new google.maps.LatLng(36.163989578823994, -86.78294777870178)], affiliation.HAZMAT)); });
    timed_event(327194*coefficient, function() { window.hazmatTask6 = last_item; });
	timed_event(328200*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.165024150155496, -86.78368538618088)); });
	timed_event(328200*coefficient, function() { trigger(map, 'move_item', hazmat_6, new LatLng(36.164341503950496, -86.78346812725067)); });
	timed_event(390219*coefficient, function() { trigger(map, 'delete_item', suspObj4); });
	timed_event(390220*coefficient, function() { trigger(map, 'add_item', static_icon, static_icon_options_template(map, new LatLng(36.1639852479569, -86.78297191858291), 'images/bomb.png', 40)); });
	timed_event(390222*coefficient, function() { window.suspObj4 = last_item; });

	timed_event(8190*coefficient, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.1642537610081, -86.78286999464035)); });
	timed_event(8191*coefficient, function() { hazmat_1.task = 'Classify Suspicious Object'; });
	timed_event(36190*coefficient, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.16440317513022, -86.78347080945968)); });
	timed_event(36191*coefficient, function() { hazmat_2.task = 'Classify Suspicious Object'; });
	timed_event(93190*coefficient, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.16473231827856, -86.78216189146042)); });
	timed_event(123190*coefficient, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.16486224282507, -86.78327232599258)); });
	timed_event(288190*coefficient, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.16515240686814, -86.78344935178757)); });
	timed_event(297190*coefficient, function() { trigger(map, 'move_item', hazmat_2, new LatLng(36.16379902062317, -86.78353250026703)); });
	timed_event(318190*coefficient, function() { trigger(map, 'move_item', hazmat_1, new LatLng(36.1639852479569, -86.78297191858291)); });
    */
}
google.maps.event.addDomListener(window, 'load', scenario_2);   // Note: order of listeners may not be guaranteed

/*

    Consent Form
    Demographic Survey
    Trial 1
    TLX + SART
    Trial 2
    TLX + SART
    Preference Questionnaire

    CHEATSHEET
    DEMO?
    Ask vs wait for input
    
    What is a good baseline? - all blue in normal, all green in residue
    How do you get out of details mode for faults and neglects?

    5 x each of    
    proximity to high risk objects
        3 true
        2 false
    proximity to out team robot
        wait to ask
    neglect time operation
        3 true
        2 false
    fault status
        3 true
        2 false
    operator trigger

    informed consent

    clickable details
    emulating GVA?

*/