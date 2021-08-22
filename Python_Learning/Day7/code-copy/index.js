var codes=document.getElementsByTagName("pre"),css=document.createElement("style");
window.onload=function(){
	codecopy_load();
};
window.onresize=function(){
	css.innerHTML=".codecopy{position: absolute;color: rgb(198, 120, 221);cursor: pointer;right: "+(document.body.clientWidth-codes[0].clientWidth)/2+"px}";
}
function codecopy_load()
{
	css.rel="stylesheet";
	css.innerHTML=".codecopy{position: absolute;color: rgb(198, 120, 221);cursor: pointer;right: "+(document.body.clientWidth-codes[0].clientWidth)/2+"px}";
	document.body.appendChild(css);
	for(let i=codes.length-1;i>=0;i--)
	{
		var copy=document.createElement("div");
		copy.innerHTML="copy";
		copy.className="codecopy";
		copy.onclick=function(){
			codecopy(i);
		}
		copy.code=i;
		codes[i].insertBefore(copy,codes[i].firstChild);
		codecopy_yc(copy,codes[i]);
	}
}
function codecopy(id)
{
	var COPY=document.createElement("textarea");
	document.body.appendChild(COPY);
	COPY.value=document.getElementsByTagName("pre")[id].innerText.replace("copy\n","");
	COPY.select();
	document.execCommand("copy");
	COPY.remove();
	spop({
		template:"复制成功!",
		style:"success",
		autoclose:2000
	});
}
function codecopy_yc(obj,f)
{
	obj.style.display="none";
	f.onmouseover=function(){
		obj.style.display="";
	};
	f.onmouseout=function(){
		obj.style.display="none";
	};
}