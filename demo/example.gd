extends Node


func _ready() -> void:
	var example := ExampleClass.new()
	example.print_type(example)
	
	var scriptContext = QuickJSContext.new()
	scriptContext.bind_Variant()
	scriptContext.bind_ObjectHandle()
	scriptContext.bind_ReferenceHandle()
	scriptContext.eval("console.log('Hello, World!')")
	scriptContext.eval("
		var ref = new ReferenceHandle('res://printer.gd', 1);
		var nameVar = VariantObject.fromString(\"Himiko\")
		var nameStr = nameVar.toString();
		console.log(\"Himiko\");
		console.log(nameStr);
		console.log(ref.isValid());
		ref.call('helloWorld');
		ref.call('sayHello', nameVar);
	")
	
	var haxeJsFile = FileAccess.open("res://haxetest1/bin/main.js", FileAccess.READ)
	var haxeJsContents = haxeJsFile.get_as_text()
	scriptContext.eval(haxeJsContents)
	
	var haxeEs6JsFile = FileAccess.open("res://haxetest1/bin/main.js", FileAccess.READ)
	var haxeEs6JsContents = haxeEs6JsFile.get_as_text()
	scriptContext.eval(haxeEs6JsContents)
	
