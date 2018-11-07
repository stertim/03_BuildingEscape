// Copyright Tim Sterling 2018.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Had to make these properties protected (or public) rather than private to expose to blueprints...
	//UPROPERTY(VisibleAnywhere)
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DoorCloseDelay = 1.0f;
	*/
private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	FRotator DoorClosedRotation;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;
	
	// The owning door.
	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
