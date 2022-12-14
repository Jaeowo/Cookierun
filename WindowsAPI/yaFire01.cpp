#include "yaFire01.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaTime.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"		
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
    Fire01::Fire01(Vector2 pos)
        :mSpeed(-300.0f)
        , mState(eState::None)
    {
        SetPos({ 2000.0f, 650.0f });
        SetPos(pos);
        mAnimator = new Animator();

        mAnimator->CreateAnimations(L"..\\Resources\\Image\\Map\\Fire01"
            , L"Fire01", Vector2(0, 0), 0.15f);

        mAnimator->Play(L"Fire01", true);

        AddComponent(mAnimator);

        eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
        if (type != eSceneType::JellyTool)
        {
            Collider* col = new Collider();
            col->SetPos(pos);
            AddComponent(col);
        }

    }

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
        if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Death)
        {
            mSpeed = 0;
        }

        if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Run)
        {
            mSpeed = -500.0f;
        }
        else
        {
            mSpeed = -300.0f;
        }
       
        switch (mState)
        {
        case ya::Fire01::eState::None:
        {

        }
        break;
        case ya::Fire01::eState::Away:
        {
            Vector2 pos = this->GetPos();
            //???? ?????????? -?? ?? ??????
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
            Sound* sound2 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
            sound2->Load(L"..\\Resources\\Sound\\g_giantland.wav");
            sound2->Play(false);
            mState = eState::Away;
          
        }
        else if (playerObj->GetState() == Player::eState::Mujuk
                || playerObj->GetState() == Player::eState::MujukJump
                || playerObj->GetState() == Player::eState::MujukSlide)
        {
        }
        else if (playerObj->GetState() == Player::eState::Death)
        {

        }
        else if (playerObj->GetState() == Player::eState::Run
            || playerObj->GetState() == Player::eState::RunJump
            || playerObj->GetState() == Player::eState::RunSlide)
        {
            mState = eState::Away;
            Sound* sound3 = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
            sound3->Load(L"..\\Resources\\Sound\\g_giantland.wav");
            sound3->Play(false);
        }
        else
        {
            Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
            sound->Load(L"..\\Resources\\Sound\\g_obs1.wav");
            sound->Play(false);
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