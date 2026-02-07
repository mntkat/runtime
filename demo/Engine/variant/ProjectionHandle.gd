extends RefCounted

var proj := Projection()

func getX():
	return proj.x

func setX(value):
	proj.x = value
	return proj.x

func getY():
	return proj.y

func setY(value):
	proj.y = value
	return proj.y

func getZ():
	return proj.x

func setZ(value):
	proj.z = value
	return proj.z

func getW():
	return proj.w

func setW(value):
	proj.w = value
	return proj.w

func fromTransform3D(from: Transform3D):
	proj = Projection(from)

func createDepthCorrection(flipY: bool):
	proj = Projection.create_depth_correction(flipY)

func createFitAABB(aabb: AABB):
	proj = Projection.create_fit_aabb(aabb)

func createForHmd(eye, aspect, intraocularDist, displayWidth, displayToLens, oversample, zNear, zFar):
	proj = Projection.create_for_hmd(eye, aspect, intraocularDist, displayWidth, displayToLens, oversample, zNear, zFar)

func createFrustum(left, right, bottom, top, zNear, zFar):
	proj = Projection.create_frustum(left, right, bottom, top, zNear, zFar)

func createFrustumAspect(size, aspect, offset, zNear, zFar, flipFov := false):
	proj = Projection.create_frustum_aspect(size, aspect, offset, zNear, zFar, flipFov)

func createLightAtlasRect(rect):
	proj = Projection.create_light_atlas_rect(rect)

func createOrthogonal(left, right, bottom, top, zNear, zFar):
	proj = Projection.create_orthogonal(left, right, bottom, top, zNear, zFar)

func createOrthogonalAspect(size, apsect, zNear, zFar, flipFov := false):
	proj = Projection.create_orthogonal_aspect(size, apsect, zNear, zFar, flipFov)

func createPerspective(fovy: float)
