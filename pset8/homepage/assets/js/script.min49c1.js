$(window).on("load",function(){setTimeout(function(){$(".page-loader").fadeOut()},500)}),$(".datepicker").each(function(){new Pikaday({field:this})});