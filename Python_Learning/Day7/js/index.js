class BOX {
	constructor(name,anchor,icon) {
		if(icon==undefined)icon='tool';//检测,如果icon没有值,则用默认值
		var temp=document.getElementById("navItem");//获取侧边栏元素地址
		temp.innerHTML=temp.innerHTML+'<li><a href="#'+anchor+'"><i class="iconfont icon-'+icon+'"></i>'+name+'</a></li>';
		temp=document.getElementById("mainContent");//获取mian的地址
		this.box=document.createElement("div");//创建box元素
		this.box.className="box";
		this.box.innerHTML='<a href="#" name="'+anchor+'"></a><div class="sub-category"><div><i class="iconfont icon-'+icon+'"></i>'+name+'</div>'
		temp.insertBefore(this.box,temp.lastChild);//吧box元素添加到mian里的footer前
	}
	add(url,name,introduce,logo){
		var Logo='no-logo',temp='';//没什么好说的,设置默认值
		if(logo!=undefined){
			Logo='logo';
			temp='<img src='+logo+'> ';
		}
		var temp_1='';
		if(introduce!=undefined){
			temp_1='<div class="desc">'+introduce+'</div>';
		}
		//添加到一个导航元素到尾部
		this.box.innerHTML=this.box.innerHTML+'<div><a target="_blank" href="'+url+'"><div class="item"><div class="'+Logo+'">'+temp+name+'</div>'+temp_1+'</div></a></div>';
	}
	adds(arg){
		let l=arg.length;
		for(let i=0;i<l;i++)
		{
			this.add(arg[i][0],arg[i][1],arg[i][2],arg[i][3]);//依次调用
		}
	}
};
