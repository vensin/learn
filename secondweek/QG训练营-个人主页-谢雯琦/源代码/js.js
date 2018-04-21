var odiv=document.getElementById("card");
console.log(odiv);
var oli=odiv.getElementsByTagName("li");
var opic=odiv.getElementsByTagName("div");
function change(nindex) 
{
	for(var j=0;j<opic.length;j++)
	{
		opic[j].className="";
	}
	opic[nindex].className="select";
}
for (var i=0;i<oli.length;i++) 
{
	oli[i].s=i;
	oli[i].onclick=function()
	{
		change(this.s);
	}
}