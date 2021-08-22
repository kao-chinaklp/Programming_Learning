function loadFile(filePath) {
  var result = null;
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", filePath, false);
  xmlhttp.send();
  if (xmlhttp.status==200) {
    result = xmlhttp.responseText;
  }
  return result;
}
function f(a,b)
{
	var i=0,k=0,str="";
	while(a[i])if(a[i++]=='\n')k++;//取一共行数
	k=Math.floor(Math.random()*k);i=0;//取随机行
	while(a[i])
	{
		if(a[i++]=='\n')k--;
		if(k===0)
		{
			while(a[i]!='\n')str+=a[i++];//获取第i行内容
			return str;
		}
	}
	return str;
}
var $_GET = (function(){
    var url = window.document.location.href.toString();
    var u = url.split("?");
    if(typeof(u[1]) == "string"){
        u = u[1].split("&");
        var get = {};
        for(var i in u){
            var j = u[i].split("=");
            get[j[0]] = j[1];
        }
        return get;
    } else {
        return {};
    }
})();
function get_du(id,pngid)
{
	var s=$_GET['s'],du=document.getElementById("du");
	var file="https://cdn.jsdelivr.net/gh/xihale/-test@master/%E6%AF%92%E9%B8%A1%E6%B1%A4/dutang.txt";
	if(s)
	{
		file="https://cdn.jsdelivr.net/gh/xihale/-test@master/%E6%AF%92%E9%B8%A1%E6%B1%A4/"+s+".txt";
		document.getElementById(pngid).src="https://cdn.jsdelivr.net/gh/xihale/-test@master/%E6%AF%92%E9%B8%A1%E6%B1%A4/img/logo_"+s+".png";
		du.className="btn btn-primary btn-filled btn-xs";
		du.innerHTML="毒鸡汤";
	}
	var fs=loadFile(file),u=f(fs,'\n');
	document.getElementById(id).innerHTML=u;
}
