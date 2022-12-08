// Http Server Example created by Aleksey Usanov

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpServerRequest.h"
#include "HttpResultCallback.h"
#include "HttpServer.generated.h"

UCLASS()
class HTTPSERVEREXAMPLE_API AHttpServer : public AActor
{
	GENERATED_BODY()
	
public:	
	AHttpServer();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Http")
	bool IsServerStarted() const { return _isServerStarted; }

private:
	void StartServer();
	void StopServer();

	// Callbacks for HttpRequests
	bool RequestGET(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete);
	bool RequestPOST(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete);
	bool RequestPUT(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete);

	// Just print request for example
	void RequestPrint(const FHttpServerRequest& Request, bool PrintBody = true);

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Http")
	FString HttpPathGET = TEXT("/get");

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Http")
	FString HttpPathPOST = TEXT("/post");

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Http")
	FString HttpPathPUT = TEXT("/put");

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Http")
	int32 ServerPort = 8080;

private:
	bool _isServerStarted = false;

};
