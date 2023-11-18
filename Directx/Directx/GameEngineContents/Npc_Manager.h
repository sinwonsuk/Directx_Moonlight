#pragma once
class Npc_Manager
{
public:


	void RightIdleUpdate(float _Time);
	void LeftIdleUpdate(float _Time);
	void DownIdleUpdate(float _Time);
	void UpIdleUpdate(float _Time);

	void RightMoveUpdate(float _Time);
	void LeftMoveUpdate(float _Time);
	void DownMoveUpdate(float _Time);
	void UpMoveUpdate(float _Time);
};

