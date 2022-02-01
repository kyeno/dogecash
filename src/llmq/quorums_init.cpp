// Copyright (c) 2018-2021 The Dash Core developers
// Copyright (c) 2021 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "llmq/quorums_init.h"

#include "bls/bls_worker.h"
#include "llmq/quorums_blockprocessor.h"


namespace llmq
{

CBLSWorker* blsWorker;

void InitLLMQSystem(CEvoDB& evoDb)
{
    blsWorker = new CBLSWorker();
    quorumBlockProcessor.reset(new CQuorumBlockProcessor(evoDb));
    /* !TODO
    quorumDKGSessionManager.reset(new CDKGSessionManager(evoDb, *blsWorker));
    */
}

void DestroyLLMQSystem()
{
    quorumBlockProcessor.reset();
    //quorumDKGSessionManager.reset();
    delete blsWorker;
    blsWorker = nullptr;
}

void StartLLMQSystem()
{
    if (blsWorker) {
        blsWorker->Start();
    }
}

void StopLLMQSystem()
{
    if (blsWorker) {
        blsWorker->Stop();
    }
}

} // namespace llmq
