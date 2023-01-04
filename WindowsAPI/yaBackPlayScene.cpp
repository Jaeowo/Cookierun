#include "yaBackPlayScene.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaAnimator.h"
#include "yaApplication.h"
#include "yaSceneManager.h"

namespace ya
{
	BackPlayScene::BackPlayScene(Vector2 pos)
		: mSpeed(-300.0f)
	{
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(900.0f, 1000.0f));
		//col->SetOffset(Vector2(50.0f, 55.0f));
		AddComponent(col);
	}
	BackPlayScene::BackPlayScene()
	{
	}
	BackPlayScene::~BackPlayScene()
	{
	}
	void BackPlayScene::Tick()
	{
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
		if (type != eSceneType::JellyTool)
			Translate(mSpeed);
		GameObject::Tick();
	}
	void BackPlayScene::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BackPlayScene::OnCollisionEnter(Collider* other)
	{

		//Player* playerobj = dynamic_cast<Player*>(mTarget);
		//playerobj->SetState(Player::eState::Back);

		//SceneManager::ChangeScene(eSceneType::Play);
		
	

	}
}