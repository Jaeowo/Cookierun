#include "yaLobbieCookie.h"
#include "yaAnimator.h"

namespace ya
{
	LobbieCookie::LobbieCookie()
	{
		SetPos({ 250.0f, 600.0f });
		SetScale({ 1.0f, 1.0f });
		//dd

		//�̹��� �׵θ� ��¦ ������ ���߿� ��������� �� �� ����
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Lilybell\\LobbieIdle", L"LobbieP", Vector2(0, 0), 0.2f);
		mAnimator->Play(L"LobbieP", true);

		AddComponent(mAnimator);
	}
	LobbieCookie::~LobbieCookie()
	{
	}
	void LobbieCookie::Tick()
	{
		GameObject::Tick();
	}
	void LobbieCookie::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
