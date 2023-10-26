#pragma once

class CameraCollision : public GameEngineActor
{
public:
	static CameraCollision* CameraCol;
	// constrcuter destructer
	CameraCollision();
	~CameraCollision();

	// delete Function
	CameraCollision(const CameraCollision& _Other) = delete;
	CameraCollision(CameraCollision&& _Other) noexcept = delete;
	CameraCollision& operator=(const CameraCollision& _Other) = delete;
	CameraCollision& operator=(CameraCollision&& _Other) noexcept = delete;


	std::shared_ptr<GameEngineCollision> Col;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Map_Number = 0.0f;
	
	

};

