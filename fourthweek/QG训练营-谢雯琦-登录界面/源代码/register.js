var odiv=document.getElementById("load");
var ospan=odiv.getElementsByTagName("span");
ospan[1].onclick=function () {
	layer();
}

function layer()
{
	var bg=document.createElement("div");
	bg.id="bg";	var layer=document.createElement("div");
	layer.id="layer";
	var word=document.createElement("h2");
	var form=document.createElement("form");
	var userName=document.createElement("input");
	var password=document.createElement("input");
	var login=document.createElement("input");
	var oul=document.createElement("ul");
	var li1=document.createElement("li");
	var li2=document.createElement("li");
	var res=document.createElement("a");
	// var forget=document.createElement("a");

	word.innerHTML="账号密码登录";
	userName.type="text";
	userName.name="username";
	userName.placeholder="用户名";
	password.type="password";
	password.name="password";
	password.placeholder="密码";
	login.type="submit";
	login.value="登录";
	login.id="login";
	res.innerHTML="注册";
	li2.innerHTML="忘记密码";
	// forget.innerHTML="忘记密码";
	res.href="register.html";
	// forget.href="register.html";


	layer.appendChild(word);
	layer.appendChild(oul);
	oul.appendChild(li1);
	oul.appendChild(li2);
	li1.appendChild(res);
	li2.style.cursor="pointer";
	// li2.appendChild(forget);
	form.appendChild(userName);
	form.appendChild(password);
	form.appendChild(login);
	layer.appendChild(form);

	document.body.appendChild(bg);
	document.body.appendChild(layer);

	bg.onclick=function()
	{
		document.body.removeChild(bg);
		document.body.removeChild(layer);
	}

	li2.onclick=function()
	{
		var title=document.createElement("h2");
		var a=document.createElement("a");
		var img=document.createElement("img");
		layer.removeChild(word);
		layer.removeChild(form);
		layer.removeChild(oul);

		title.innerHTML="啊你忘记了啊，我也没办法呢！";
		title.id="title";
		a.innerHTML="要不...再注册一次？";
		a.id="go";
		a.href="register.html";
		img.src="../image/see.jpg";
		layer.appendChild(img);
		layer.appendChild(title);
		layer.appendChild(a);
	}
}

