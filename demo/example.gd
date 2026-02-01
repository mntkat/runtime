extends Node


func _ready() -> void:
	var example := ExampleClass.new()
	example.print_type(example)
	
	var scriptContext = QuickJSContext.new()
	scriptContext.eval("console.log('Hello, World!')")
