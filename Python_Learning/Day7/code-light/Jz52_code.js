$(document).ready(function(){var copyimg=bloghost+"zb_users/plugin/Jz52_code/copy.svg";$("pre").each(function(){var id=$(this).attr("data");var prev=$(this).prev();var btn='<img class="Jz52_code" data-clipboard-target="'+id+'" src="'+copyimg+'" style="cursor: pointer;vertical-align: middle;" title="点击复制代码"> ';if(prev.hasClass("prism-show-language")){prev.find("div").prepend(btn)}else{$(this).before('<div class="prism-show-language"><div class="prism-show-language-label" data-language="default">'+btn+"</div>")}});var clip=new ClipboardJS(".Jz52_code",{target:function(trigger){return trigger.parentNode.parentNode.nextSibling}});clip.on("success",function(e){alert("复制成功");e.clearSelection()});clip.on("error",function(e){alert("复制失败")})});