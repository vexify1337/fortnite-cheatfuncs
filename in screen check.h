auto IsInScreen(fvector2d screen_location) -> bool
{
	if (screen_location.x > 0 && screen_location.x < globals.ScreenWidth && screen_location.y > 0 && screen_location.y < globals.ScreenHeight) return true;
	else return false;
}
