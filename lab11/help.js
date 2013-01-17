	function showHint(str)	
	{
	  var xmlhttp;
	  if (str.length==0)
	  {
	  document.getElementById("txtHint").innerHTML="";
	  return;
	  }
	  if (window.XMLHttpRequest)   // IE7+,Firefox,Chrome,Opera, Safari
	  {
	  xmlhttp=new XMLHttpRequest();
	  }
	  else              // code for IE6, IE5
	  {
	  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	  }
	  xmlhttp.onreadystatechange=function()
	  {
	    if (xmlhttp.readyState==4 &&xmlhttp.status==200)
	    {
	      document.getElementById("txtHint").innerHTML=xmlhttp.responseText;
	    }
	  }
	  xmlhttp.open("GET","http://www.cs.bgu.ac.il/~chenisr/suggest.php?q="+str,true);
	  xmlhttp.send();
	}



	function Val()
	{
	  
	  
	  if(event.keyCode >=48 & event.keyCode<=57)
	  {
	    event.returnValue=false;
	  }
	 else
	 {
	    showHint(document.getElementById("un").value);
	 }
	}
	  function Lo()
	  {
	    var y=document.getElementById("un").value;
	    if (y.length==0)
		alert("no empty username");
	    else
	    {
	    var x=document.getElementById("ps").value;
	      if (x.length<4) 
		  alert("short pass");
	      else
		if(!((x.charCodeAt(0)>=65 && x.charCodeAt(0) <=90) || (x.charCodeAt(0)>=97 && x.charCodeAt(0) <=122)))
		  alert("put the first character letter");
	    }
	  }
