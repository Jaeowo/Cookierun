#include "yaFire01.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
    Fire01::Fire01()
        :mSpeed (-300.0f)
    {
        SetPos({ 1800.0f, 650.0f });
        mAnimator = new Animator();

        mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Fire01"
            , L"Fire01", Vector2(0, 0), 0.15f);

        mAnimator->Play(L"Fire01", true);

        AddComponent(mAnimator);

        Collider* col = new Collider();
        AddComponent(col);
    }
    Fire01::~Fire01()
    {
    }
    void Fire01::Tick()
    {
        GameObject::Tick();
        Translate(mSpeed);
    }
    void Fire01::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void Fire01::OnCollisionEnter(Collider* other)
    {
        Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
        playerObj->SetState(Player::eState::Attack);
        playerObj->GetComponent<Animator>()->Play(L"AttackC", false);

        int hp = playerObj->GetHp();
        hp -= 10;
        playerObj->SetHp(hp);
    }
    void Fire01::OnCollisionStay(Collider* other)
    {
    }
    void Fire01::OnCollisionExit(Collider* other)
    {
    }
}