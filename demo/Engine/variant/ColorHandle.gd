extends RefCounted

var color: Color = Color()

func getA():
	return color.a

func setA(value):
	color.a = value
	return color.a

func getA8():
	return color.a8

func setA8(value):
	color.a8 = value
	return color.a8

func getB():
	return color.b

func setB(value):
	color.b = value
	return color.b

func getB8():
	return color.b8
	
func setB8(value):
	color.b8 = value
	return color.b8

func getG():
	return color.g

func setG(value):
	color.g = value

func getG8():
	return color.g8

func setG8(value):
	color.g8 = value
	return color.g8

func getH():
	return color.h

func setH(value):
	color.h = value
	return color.h

func getOkHslH():
	return color.ok_hsl_h

func setOkHslH(value):
	color.ok_hsl_h = value
	return color.ok_hsl_h

func getOkHslL():
	return color.ok_hsl_l

func setOkHslL(value):
	color.ok_hsl_l = value
	return color.ok_hsl_l

func getOkHslS():
	return color.ok_hsl_s

func setOkHslS(value):
	color.ok_hsl_s = value
	return color.ok_hsl_s

func getR():
	return color.r

func setR(value):
	color.r = value
	return color.r

func getR8():
	return color.r8

func setR8(value):
	color.r8 = value
	return color.r8

func getS():
	return color.s

func setS(value):
	color.s = value
	return color.s

func getV():
	return color.v

func setV(value):
	color.v = value
	return color.v

func blend(over):
	return color.blend(over)

func clamp(p_min, p_max):
	return color.clamp(p_min, p_max)

func darkened(amount):
	return color.darkened(amount)

func fromHsv(h, s, v, alpha = 1.0):
	color = Color.from_hsv(h, s, v, alpha)

func fromOkHsl(h, s, l, alpha = 1.0):
	color = Color.from_ok_hsl(h, s, l, alpha)

func fromRgba8(r8, g8, b8, a8 = 255):
	color = Color.from_rgba8(r8, g8, b8, a8)

func fromRgba9995(rgbe):
	color = Color.from_rgbe9995(rgbe)

func fromString(p_str, default):
	color = Color.from_string(p_str, default)

func fromColorAndAlpha(from, alpha):
	color = Color(from, alpha)

func fromCode(code: String):
	color = Color(code)

func fromCodeAndAlpha(code: String, alpha):
	color = Color(code, alpha)

func getLuminance():
	return color.get_luminance()

func hex(p_hex):
	color = Color.hex(p_hex)

func hex64(p_hex):
	color = Color.hex64(p_hex)

func html(rgbe: String):
	color = Color.html(rgbe)

func htmlIsValid(colorStr):
	return Color.html_is_valid(colorStr)

func inverted():
	return color.inverted()

func isEqualApprox(to):
	return color.is_equal_approx(to)

func lerp(to, weight):
	return color.lerp(to, weight)

func lightened(amount):
	return color.lightened(amount)

func linearToSrgb():
	return color.linear_to_srgb()

func srgbToLinear():
	return color.srgb_to_linear()

func toAbgr32():
	return color.to_abgr32()

func toAbgr64():
	return color.to_abgr64()

func toArgb32():
	return color.to_argb32()

func toArgb64():
	return color.to_argb64()

func toHtml(withAlpha = true):
	return color.to_html(withAlpha)

func toRgba32():
	return color.to_rgba32()

func toRgba64():
	return color.to_rgba64()

func multiply(right):
	return color * right

func add(right):
	return color + right

func subtract(right):
	return color - right

func divide(right):
	return color / right

func lessThan(right) -> bool:
	return color < right

func lessThanOrEqualTo(right) -> bool:
	return color <= right

func greaterThan(right) -> bool:
	return color > right

func greaterThanOrEqualTo(right) -> bool:
	return color >= right

func isEqualTo(right) -> bool:
	return color == right
