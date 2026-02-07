extends RefCounted

var rect := Rect2i()

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
	rect = Rect2i(pos, size)

func fromXYWH(x, y, w, h):
	rect = Rect2i(x, y, w, h)

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

func merge(b):
	return rect.merge(b)

func isEqualTo(right: Rect2i) -> bool:
	return rect == right
