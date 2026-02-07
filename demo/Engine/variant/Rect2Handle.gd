extends RefCounted

var rect := Rect2()

func getEnd():
	return rect.end

func setEnd(value):
	rect.end = value
	return rect.end

func getPosition():
	return rect.position

func setPosition(value):
	rect.position = value
	return rect.position

func getSize():
	return rect.size

func setSize(value):
	rect.size = value
	return rect.size

func fromPositionAndSize(pos, size):
	rect = Rect2(pos, size)

func fromXYWH(x, y, w, h):
	rect = Rect2(x, y, w, h)

func abs():
	return rect.abs()

func encloses(b):
	return rect.encloses(b)

func expand(to):
	return rect.expand(to)

func getArea():
	return rect.get_area()

func getCenter():
	return rect.get_center()

func getSupport(direction):
	return rect.get_support(direction)

func grow(amount):
	return rect.grow(amount)

func growIndividual(left, top, right, bottom):
	return rect.grow_individual(left, top, right, bottom)

func growSide(side, amount):
	return rect.grow_side(side, amount)

func hasArea():
	return rect.has_area()

func hasPoint(point):
	return rect.has_point(point)

func intersection(b):
	return rect.intersection(b)

func intersects(b, includeBorders := false):
	return rect.intersects(b, includeBorders)

func isEqualApprox(pRect):
	return rect.is_equal_approx(pRect)

func isFinite():
	return rect.is_finite()

func merge(b):
	return rect.merge(b)

func multiply(right):
	return rect * right

func isEqualTo(right: Rect2) -> bool:
	return rect == right
