//*****************************************************************************
//Preloads the images used in the program, called by the initialize function.
//Adapted from code found at:
//http://www.techrepublic.com/article/preloading-and-the-javascript-image-object/
//*****************************************************************************
/*function preloader() 
{
    var parent = document.getElementById("thisN");
    var child = document.getElementById("preloader");
    var i = 0;

    // create object
    var image;
    images = new Array();

	// set image list
	images.push('images/respondertriagelevelunknown.png');
	images.push('images/respondertriagelevel1.png');
	images.push('images/respondertriagelevel2.png');
	images.push('images/respondertriagelevel3.png');
	images.push('images/respondertriagelevel4.png');
	images.push('images/respondertriagelevel5.png');
	images.push('images/respondertriagelevelunknownnonambulatory.png');
	images.push('images/respondertriagelevel1nonambulatory.png');
	images.push('images/respondertriagelevel2nonambulatory.png');
	images.push('images/respondertriagelevel3nonambulatory.png');
	images.push('images/respondertriagelevel4nonambulatory.png');
	images.push('images/respondertriagelevel5nonambulatory.png');
	images.push('images/respondertriagelevelunknownunknown.png');
	images.push('images/respondertriagelevel1unknown.png');
	images.push('images/respondertriagelevel2unknown.png');
	images.push('images/respondertriagelevel3unknown.png');
	images.push('images/respondertriagelevel4unknown.png');
	images.push('images/respondertriagelevel5unknown.png');
	images.push('images/victimtriagelevelunknown.png');
	images.push('images/victimtriagelevel1.png');
	images.push('images/victimtriagelevel2.png');
	images.push('images/victimtriagelevel3.png');
	images.push('images/victimtriagelevel4.png');
	images.push('images/victimtriagelevel5.png');
	images.push('images/victimtriagelevelunknownnonambulatory.png');
	images.push('images/victimtriagelevel1nonambulatory.png');
	images.push('images/victimtriagelevel2nonambulatory.png');
	images.push('images/victimtriagelevel3nonambulatory.png');
	images.push('images/victimtriagelevel4nonambulatory.png');
	images.push('images/victimtriagelevel5nonambulatory.png');
	images.push('images/victimtriagelevelunknownunknown.png');
	images.push('images/victimtriagelevel1unknown.png');
	images.push('images/victimtriagelevel2unknown.png');
	images.push('images/victimtriagelevel3unknown.png');
	images.push('images/victimtriagelevel4unknown.png');
	images.push('images/victimtriagelevel5unknown.png');
	images.push('images/suspiciousperson.png');
	images.push('images/victimgroup.png');
	images.push('images/egress.png');
	images.push('images/ingress-egress.png');
	images.push('images/ingress.png');
	images.push('images/a911call.png');
	images.push('images/eyewitnessreport.png');
	images.push('images/suspiciousitem.png');
	images.push('images/bomb.png');
	images.push('images/uav.png');
	images.push('images/ugv.png');
	images.push('images/HAZMATReading.png');
	images.push('images/taskmainsymbol/bombsurveillance.png');
	images.push('images/taskmainsymbol/decontaminateself.png');
	images.push('images/taskmainsymbol/gatherimagery.png');
	images.push('images/taskmainsymbol/gathersamples.png');
	images.push('images/taskmainsymbol/gotox.png');
	images.push('images/taskmainsymbol/guidevictims.png');
	images.push('images/taskmainsymbol/hazardsampling.png');
	images.push('images/taskmainsymbol/improvecommunication.png');
	images.push('images/taskmainsymbol/searcharea.png');
	images.push('images/taskmainsymbol/surveillance.png');
	images.push('images/taskmainsymbol/victimassessment.png');
	images.push('images/taskmainsymbol/victimsearch.png');
	images.push('images/diamond.png');
	var counter = 0;
	var name = "Bill";
	var numImg = images.length;
	var w=window.innerWidth
		  || document.documentElement.clientWidth
		  || document.body.clientWidth;
	var imgW = (w/numImg)-1; 
	//parent.removeChild(child);

	// A single iteration of your loop
	// log the current value of counter as an example
	// then wait before doing the next iteration
	function loadImage() {
	    name = "Img" + counter;
	    //log(name);
	    image = document.createElement("img");
	    image.setAttribute("id",name);
	    image.setAttribute("src",images[counter]);
	    image.setAttribute("alt",counter);
	    image.setAttribute("width",imgW);
	    image.setAttribute("height",imgW);
	    parent.appendChild(image);
	    counter++;
	    if (counter < images.length)
	        setTimeout(loadImage, 75);
	    else {
	        counter = 0;
	        //deleteImage();
	    }
	}
	// Start the loop    
	loadImage();

	counter = 0;
	function deleteImage() {
	    name = "Img" + counter;
	    log(name);
	    image = document.getElementById(name)
	    image.src = 'images/hmtlogo.png';
	    counter++;
	    if (counter < images.length)
	        setTimeout(deleteImage, 75);
	    else {
	        var parent = document.getElementById("bdy");
	        var child = document.getElementById("thisN");
	        parent.removeChild(child);
	    }
	}
	// Start the loop    
	//deleteImage();

} ;*/

function preloader() 
{
	var parent = document.getElementById("thisN");
	var child = document.getElementById("preloader");
	// var i = 0;	

	// // create object
	// var image;// = document.getElementById("imageObj");
 //    images = new Array();

	// // set image list
	// // images.push('images/respondertriagelevelunknown.png');
	// // images.push('images/respondertriagelevel1.png');
	// // images.push('images/respondertriagelevel2.png');
	// // images.push('images/respondertriagelevel3.png');
	// // images.push('images/respondertriagelevel4.png');
	// // images.push('images/respondertriagelevel5.png');
	// // images.push('images/respondertriagelevelunknownnonambulatory.png');
	// // images.push('images/respondertriagelevel1nonambulatory.png');
	// // images.push('images/respondertriagelevel2nonambulatory.png');
	// // images.push('images/respondertriagelevel3nonambulatory.png');
	// // images.push('images/respondertriagelevel4nonambulatory.png');
	// // images.push('images/respondertriagelevel5nonambulatory.png');
	// // images.push('images/respondertriagelevelunknownunknown.png');
	// // images.push('images/respondertriagelevel1unknown.png');
	// // images.push('images/respondertriagelevel2unknown.png');
	// // images.push('images/respondertriagelevel3unknown.png');
	// // images.push('images/respondertriagelevel4unknown.png');
	// // images.push('images/respondertriagelevel5unknown.png');
	// images.push('images/victimtriagelevelunknown.png');
	// images.push('images/victimtriagelevel1.png');
	// images.push('images/victimtriagelevel2.png');
	// images.push('images/victimtriagelevel3.png');
	// images.push('images/victimtriagelevel4.png');
	// images.push('images/victimtriagelevel5.png');
	// images.push('images/victimtriagelevelunknownnonambulatory.png');
	// images.push('images/victimtriagelevel1nonambulatory.png');
	// images.push('images/victimtriagelevel2nonambulatory.png');
	// images.push('images/victimtriagelevel3nonambulatory.png');
	// images.push('images/victimtriagelevel4nonambulatory.png');
	// images.push('images/victimtriagelevel5nonambulatory.png');
	// images.push('images/victimtriagelevelunknownunknown.png');
	// images.push('images/victimtriagelevel1unknown.png');
	// images.push('images/victimtriagelevel2unknown.png');
	// images.push('images/victimtriagelevel3unknown.png');
	// images.push('images/victimtriagelevel4unknown.png');
	// images.push('images/victimtriagelevel5unknown.png');
	// images.push('images/suspiciousperson.png');
	// images.push('images/victimgroup.png');
	// images.push('images/egress.png');
	// images.push('images/ingress-egress.png');
	// images.push('images/ingress.png');
	// images.push('images/a911call.png');
	// images.push('images/eyewitnessreport.png');
	// images.push('images/suspiciousitem.png');
	// images.push('images/bomb.png');
	// images.push('images/HAZMATReading.png');
	// images.push('images/taskmainsymbol/bombsurveillance.png');
	// images.push('images/taskmainsymbol/decontaminateself.png');
	// images.push('images/taskmainsymbol/gatherimagery.png');
	// images.push('images/taskmainsymbol/gathersamples.png');
	// images.push('images/taskmainsymbol/gotox.png');
	// images.push('images/taskmainsymbol/guidevictims.png');
	// images.push('"images/taskmainsymbol/hazardsampling.png');
	// images.push('images/taskmainsymbol/improvecommunication.png');
	// images.push('images/taskmainsymbol/searcharea.png');
	// images.push('images/taskmainsymbol/surveillance.png"');
	// images.push('images/taskmainsymbol/victimassessment.png');
	// images.push('images/taskmainsymbol/victimsearch.png');
	// images.push('images/diamond.png');


	// var counter = 0;
	// var name = "Bill";
	// var numImg = images.length;
	// var w=window.innerWidth
	// 	  || document.documentElement.clientWidth
	// 	  || document.body.clientWidth;
	// var imgW = ((w)/numImg)-1; 
	// //parent.removeChild(child);

	// // A single iteration of your loop
	// // log the current value of counter as an example
	// // then wait before doing the next iteration
	// function loadImage() {
	//     name = "Img" + counter;
	//     log(name);
	//     image = document.createElement("img");
	//     image.setAttribute("id",name);
	//     image.setAttribute("src",images[counter]);
	//     image.setAttribute("alt",counter);
	//     image.setAttribute("width",imgW);
	//     image.setAttribute("height",imgW);
	//     parent.appendChild(image);
	//     counter++;
	//     if (counter < images.length)
	//         setTimeout(loadImage, 15);
	// }

	// // Start the loop    
	// loadImage();
	// setTimeout(hideDiv, 2000);
	// function deleteImage() {
	//     name = "Img" + counter;
	//     log(name);
	//     image = document.getElementById(name)
	//     image.src = 'images/hmtlogo.png';
	//     counter++;
	//     if (counter < images.length)
	//         setTimeout(deleteImage, 75);
	// }
	function hideDiv(){
		var el = document.getElementById('thisN');
		el.style.display = 'none';
	}
} ;
