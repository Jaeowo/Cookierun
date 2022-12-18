#include "yaFire01.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaTime.h"
#include "yaApplication.h"

namespace ya
{
    Fire01::Fire01()
        :mSpeed (-300.0f)
        ,mState (eState::None)
    {
        SetPos({ 2000.0f, 650.0f });
        mAnimator = new Animator();

        mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Fire01"
            , L"Fire01", Vector2(0, 0), 0.15f);

        mAnimator->Play(L"Fire01", true);

        AddComponent(mAnimator);

        eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
        if (type != eSceneType::JellyTool)
        {
            Collider* col = new Collider();
            AddComponent(col);
        }

    }
    Fire01::~Fire01()
    {
    }
    void Fire01::Tick()
    {
    
        GameObject::Tick();
        eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
        if (type != eSceneType::JellyTool)
            Translate(mSpeed);

       
        switch (mState)
        {
        case ya::Fire01::eState::None:
        {

        }
        break;
        case ya::Fire01::eState::Away:
        {
            Vector2 pos = this->GetPos();
            //위에 매달린경우 -로 값 바꾸기
            pos.x += (400 * Time::DeltaTime());
            pos.y += (400 * Time::DeltaTime());
            this->SetPos(pos);
        }
        break;
        default:
            break;
        }
      

    }
    void Fire01::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void Fire01::OnCollisionEnter(Collider* other)
    {
        Vector2 ObPos = GetPos();

        Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
        if (playerObj->GetState() == Player::eState::BiggestJump
            || playerObj->GetState() == Player::eState::BiggestSlide
            || playerObj->GetState() == Player::eState::Biggest)
        {
            mState = eState::Away;
          
        }
        else if (playerObj->GetState() == Player::eState::Mujuk
                || playerObj->GetState() == Player::eState::MujukJump
                || playerObj->GetState() == Player::eState::MujukSlide)
        {
        }
        else
        {
            playerObj->SetState(Player::eState::Attack);
            playerObj->GetComponent<Animator>()->Play(L"AttackC", false);
            int hp = playerObj->GetHp();
            hp -= 10;
            playerObj->SetHp(hp);
        }
    }

    void Fire01::OnCollisionStay(Collider* other)
    {
    }
    void Fire01::OnCollisionExit(Collider* other)
    {

    }
}