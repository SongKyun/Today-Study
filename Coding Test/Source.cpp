void ANetTPSCharacter::TakePistol()
{
	if (bHasPistol == false)
	{
		TArray<AActor*> allActors;
		TArray<AActor*> pistolActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), allActors);
		for (int i = 0; i < allActors.Num(); i++)
		{
			if (allActors[i]->GetActorLabel().Contains(TEXT("BP_Pistol")))
			{
				pistolActors.Add(allActors[i]);
			}
		}

		for (AActor* pistol : pistolActors)
		{
			if (pistol->GetOwner() == nullptr)
			{
				float dist = FVector::Distance(pistol->GetActorLocation(), GetActorLocation());
				if (dist < distanceToGun)
				{
					pistol->SetOwner(this)
					bHasPistol = true;
					ownedPistol = pistol;

					AttackPistol(pistol);
					break;
				}
			}
		}
		else
		{
			DetachPistol();

			bHasPistol = false;
			ownedPistol->SetOwner(nullptr);
			ownedPistol = nullptr;
		}
	}
}