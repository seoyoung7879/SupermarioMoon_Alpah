// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "CppTurret.generated.h"

UCLASS()
class MARIOREALRECENT_API ACppTurret : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet1;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet2;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet3;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet4;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet5;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet6;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet7;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* violet8;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* spawnArrow;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* white;

	UPROPERTY(EditAnywhere)
	float delayTime = 10.0f;

	UPROPERTY(EditAnywhere)
	float BalldelayTime = 1.0f;



	UPROPERTY(EditAnywhere)
	TSubclassOf<class AKoopa_ball> enemy_bp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AKoopa_Violethat> violet_bp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AKoopa_WhiteHat> white_bp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AKoopa_FirstVioletHat> violet_bp1;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AKoopa_SecondVioletHat> violet_bp2;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Beam1;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Target1;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Target2;



	UPROPERTY(VisibleAnywhere)
	USceneComponent* FollowTarget;

	UPROPERTY()
	FTimerHandle ChangeTargetTimerhandle;

	UPROPERTY()
	FTimerHandle TraceTimerhandle;

	//rotation related variables
	int32 TimerCount = 0;
	FRotator LookAtRotation;
	FRotator TargetRotation;
	FRotator RotationDelta;


	UPROPERTY(EditAnywhere)
	float ChangeTargetDelay=3.5f;

	UPROPERTY(EditAnywhere)
	int32 ChangeNumber=0;

	UPROPERTY(EditAnywhere)
	float RotationRateMultiplier=1.f;

	UPROPERTY()
	AActor* Enemy;

	UFUNCTION()
	void UpdateLookAtTarget(float DeltaTime);

	UFUNCTION()
	void ChangeBeamTarget();

	UFUNCTION()
	void TraceBeam();

	UFUNCTION()
	void CheckEnemy(AActor* HitActor);

	UFUNCTION()
	void FollowEnemy(float DeltaTime);

	UFUNCTION()
	void Shoot();

	
public:	
	// Sets default values for this actor's properties
	ACppTurret();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USkeletalMeshComponent* TurretMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<class UAnimationAsset*> Anims;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 KoopaHealth=47;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float anyTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isSpin = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	

};
