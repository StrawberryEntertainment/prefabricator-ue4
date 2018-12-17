//$ Copyright 2015-18, Code Respawn Technologies Pvt Ltd - All Rights Reserved $//

#pragma once
#include "CoreMinimal.h"
#include "Asset/PrefabricatorAsset.h"
#include "Prefab/PrefabComponent.h"

#include "ComponentAssetBroker.h"

/** Asset broker for the prefab asset */
class FPrefabricatorAssetBrokerBase : public IComponentAssetBroker {
public:
	virtual bool AssignAssetToComponent(UActorComponent* InComponent, UObject* InAsset) override {
		if (UPrefabComponent* PrefabComponent = Cast<UPrefabComponent>(InComponent)) {
			UPrefabricatorAsset* PrefabAsset = Cast<UPrefabricatorAsset>(InAsset);
			if (PrefabAsset && PrefabAsset) {
				PrefabComponent->PrefabAssetInterface = PrefabAsset;
				return true;
			}
		}

		return false;
	}

	virtual UObject* GetAssetFromComponent(UActorComponent* InComponent) override
	{
		if (UPrefabComponent* PrefabComponent = Cast<UPrefabComponent>(InComponent))
		{
			return PrefabComponent->PrefabAssetInterface;
		}
		return nullptr;
	}
};

class FPrefabricatorAssetBroker : public FPrefabricatorAssetBrokerBase {
public:
	virtual UClass* GetSupportedAssetClass() override {
		return UPrefabricatorAsset::StaticClass();
	}
};

