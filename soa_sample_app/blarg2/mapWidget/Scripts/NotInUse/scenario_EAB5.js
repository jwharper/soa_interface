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

    //*******************************************************************************************************************
    //*******************************************************************************************************************
    //Begin pasting in directly from excel; after pasting, replace double ampersands with a return
    //*******************************************************************************************************************
    //*******************************************************************************************************************


    timed_event(time, function() { 
        trigger(map, 'move_item', police_1, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_2, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_3, new LatLng(36.1646437962368, -86.78313553333282));
        trigger(map, 'move_item', police_4, new LatLng(36.1646437962368, -86.78313553333282)); 
    });

    // tr
    timed_event(2000, function() { 
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


}
google.maps.event.addDomListener(window, 'load', scenario_2);   // Note: order of listeners may not be guaranteed