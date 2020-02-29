#include "stdafx.h"

namespace Offsets {
	PVOID *uWorld = 0;

	namespace Engine {
		namespace World {
			DWORD OwningGameInstance = 0;
			DWORD Levels = 0;
		}

		namespace Level {
			DWORD AActors = 0x98;
		}

		namespace GameInstance {
			DWORD LocalPlayers = 0;
		}

		namespace Player {
			DWORD PlayerController = 0;
		}

		namespace Controller {
			DWORD ControlRotation = 0;
			PVOID SetControlRotation = 0;
		}

		namespace PlayerController {
			DWORD AcknowledgedPawn = 0;
		}

		namespace Pawn {
			DWORD PlayerState = 0;
		}

		namespace PlayerState {
			PVOID GetPlayerName = 0;
		}

		namespace Actor {
			DWORD RootComponent = 0;
		}

		namespace Character {
			DWORD Mesh = 0;
		}

		namespace SceneComponent {
			DWORD RelativeLocation = 0;
			DWORD ComponentVelocity = 0;
		}

		namespace StaticMeshComponent {
			DWORD ComponentToWorld = 0x1C0;
			DWORD StaticMesh = 0;
		}

		namespace SkinnedMeshComponent {
			DWORD CachedWorldSpaceBounds = 0;
		}
	}

	namespace FortniteGame {
		namespace FortPawn {
			DWORD bIsDBNO = 0;
			DWORD bIsDying = 0;
			DWORD CurrentWeapon = 0;
		}

		namespace FortPickup {
			DWORD PrimaryPickupItemEntry = 0;
		}

		namespace FortItemEntry {
			DWORD ItemDefinition = 0;
		}

		namespace FortItemDefinition {
			DWORD DisplayName = 0;
			DWORD Tier = 0;
		}

		namespace FortPlayerStateAthena {
			DWORD TeamIndex = 0;
		}

		namespace FortWeapon {
			DWORD WeaponData = 0;
		}

		namespace FortWeaponItemDefinition {
			DWORD WeaponStatHandle = 0;
		}

		namespace FortProjectileAthena {
			DWORD FireStartLoc = 0;
		}

		namespace FortBaseWeaponStats {
			DWORD ReloadTime = 0;
		}

		namespace BuildingContainer {
			DWORD bAlreadySearched = 0;
		}
	}

	namespace UI {
		namespace ItemCount {
			DWORD ItemDefinition = 0;
		}
	}

	BOOLEAN Initialize() {
		auto addr = Util::FindPattern("\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x74\x3B\x41", "xxx????xxxxxx");
		if (!addr) {
			MessageBox(0, L"Failed to find uWorld", L"Failure", 0);
			return FALSE;
		}

		uWorld = reinterpret_cast<decltype(uWorld)>(RELATIVE_ADDR(addr, 7));

		Engine::Controller::SetControlRotation = Util::FindObject(L"/Script/Engine.Controller.SetControlRotation");
		if (!Engine::Controller::SetControlRotation) {
			MessageBox(0, L"Failed to find SetControlRotation", L"Failure", 0);
			return FALSE;
		}

		Engine::PlayerState::GetPlayerName = Util::FindObject(L"/Script/Engine.PlayerState.GetPlayerName");
		if (!Engine::PlayerState::GetPlayerName) {
			MessageBox(0, L"Failed to find GetPlayerName", L"Failure", 0);
			return FALSE;
		}

		std::vector<Offsets::OFFSET> offsets{
			{ xorstr(L"/Script/Engine.World.OwningGameInstance"), Engine::World::OwningGameInstance },
			{ xorstr(L"/Script/Engine.World.Levels"), Engine::World::Levels },
			{ xorstr(L"/Script/Engine.GameInstance.LocalPlayers"), Engine::GameInstance::LocalPlayers },
			{ xorstr(L"/Script/Engine.Player.PlayerController"), Engine::Player::PlayerController },
			{ xorstr(L"/Script/Engine.PlayerController.AcknowledgedPawn"), Engine::PlayerController::AcknowledgedPawn },
			{ xorstr(L"/Script/Engine.Controller.ControlRotation"), Engine::Controller::ControlRotation },
			{ xorstr(L"/Script/Engine.Pawn.PlayerState"), Engine::Pawn::PlayerState },
			{ xorstr(L"/Script/Engine.Actor.RootComponent"), Engine::Actor::RootComponent },
			{ xorstr(L"/Script/Engine.Character.Mesh"), Engine::Character::Mesh },
			{ xorstr(L"/Script/Engine.SceneComponent.RelativeLocation"), Engine::SceneComponent::RelativeLocation },
			{ xorstr(L"/Script/Engine.SceneComponent.ComponentVelocity"), Engine::SceneComponent::ComponentVelocity },
			{ xorstr(L"/Script/Engine.StaticMeshComponent.StaticMesh"), Engine::StaticMeshComponent::StaticMesh },
			{ xorstr(L"/Script/Engine.SkinnedMeshComponent.CachedWorldSpaceBounds"), Engine::SkinnedMeshComponent::CachedWorldSpaceBounds },
			{ xorstr(L"/Script/FortniteGame.FortPawn.bIsDBNO"), FortniteGame::FortPawn::bIsDBNO },
			{ xorstr(L"/Script/FortniteGame.FortPawn.bIsDying"), FortniteGame::FortPawn::bIsDying },
			{ xorstr(L"/Script/FortniteGame.FortPlayerStateAthena.TeamIndex"), FortniteGame::FortPlayerStateAthena::TeamIndex },
			{ xorstr(L"/Script/FortniteGame.FortPickup.PrimaryPickupItemEntry"), FortniteGame::FortPickup::PrimaryPickupItemEntry },
			{ xorstr(L"/Script/FortniteGame.FortItemDefinition.DisplayName"), FortniteGame::FortItemDefinition::DisplayName },
			{ xorstr(L"/Script/FortniteGame.FortItemDefinition.Tier"), FortniteGame::FortItemDefinition::Tier },
			{ xorstr(L"/Script/FortniteGame.FortItemEntry.ItemDefinition"), FortniteGame::FortItemEntry::ItemDefinition },
			{ xorstr(L"/Script/FortniteGame.FortPawn.CurrentWeapon"), FortniteGame::FortPawn::CurrentWeapon },
			{ xorstr(L"/Script/FortniteGame.FortWeapon.WeaponData"), FortniteGame::FortWeapon::WeaponData },
			{ xorstr(L"/Script/FortniteGame.FortWeaponItemDefinition.WeaponStatHandle"), FortniteGame::FortWeaponItemDefinition::WeaponStatHandle },
			{ xorstr(L"/Script/FortniteGame.FortProjectileAthena.FireStartLoc"), FortniteGame::FortProjectileAthena::FireStartLoc },
			{ xorstr(L"/Script/FortniteGame.FortBaseWeaponStats.ReloadTime"), FortniteGame::FortBaseWeaponStats::ReloadTime },
			{ xorstr(L"/Script/FortniteGame.BuildingContainer.bAlreadySearched"), FortniteGame::BuildingContainer::bAlreadySearched },
		};

		return Util::GetOffsets(offsets);
	}
}