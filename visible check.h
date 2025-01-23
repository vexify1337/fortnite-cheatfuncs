bool IsEnemyVisible(uintptr_t mesh)
{
	auto Seconds = Kernel.Read<double>(pointer.UWorld + 0x148);
	auto LastRenderTime = Kernel.Read<float>(mesh + 0x30C);
	return Seconds - LastRenderTime <= 0.06f;
}
