extends Node


func _ready() -> void:
	var example := ExampleClass.new()
	example.print_type(example)
	
	var scriptContext = QuickJSContext.new()
	scriptContext.eval("console.log('Hello, World!')")
	
	var haxeJsFile = FileAccess.open("res://haxetest1/bin/main.js", FileAccess.READ)
	var haxeJsContents = haxeJsFile.get_as_text()
	scriptContext.eval(haxeJsContents)
	
	var haxeEs6JsFile = FileAccess.open("res://haxetest1/bin/main.js", FileAccess.READ)
	var haxeEs6JsContents = haxeEs6JsFile.get_as_text()
	scriptContext.eval(haxeEs6JsContents)
