var up = 0;
var left = 0;
var right = 0;
var down = 0;
	
document.onkeydown = function(e) {
	switch (e.keyCode) {
		case 37:
			leftKey();
			break;
		case 38:
			upKey();
			break;
		case 39:
			rightKey();
			break;
		case 40:
			downKey();
			break;
	}
};
function httpGet(url)
{
	var xmlHttp = new XMLHttpRequest();
	xmlHttp.open( "GET", url, false ); // false for synchronous request
	xmlHttp.send( null );
};

function rightKey(){
	left=0;
	if(right>2){}
	else{
		httpGet("/right="+right);
		console.log("right "+ right+ ",left " +left);
		right++;
	}
};
	
function leftKey(){
	right=0;
	if(left>2){}
	else{
		httpGet("/left="+left);
		console.log("left "+ left+ ",right " +right);
		left++;
	}
};

function upKey(){
	down=0;	
	if(up>2){}
	else{
		httpGet("/up="+up);
		console.log("up "+ up+ ",down " +down);
		up++;
	}
};

	
function downKey(){
	up=0;
	if(down>2){}
	else{
		httpGet("/down="+down);
		console.log("up "+ up+ ",down " +down);
		down++;
	}
};




