/* Copyright (c) 2013 - All Rights Reserved
 *   Thomas Hauth  <Thomas.Hauth@cern.ch>
 *   Joram Berger  <Joram.Berger@cern.ch>
 *   Dominik Haitz <Dominik.Haitz@kit.edu>
 */

#pragma once

#include "Artus/Core/interface/Cpp11Support.h"
#include "Artus/Core/interface/ProducerBase.h"

#include "TestTypes.h"

typedef ProducerBase<TestTypes> TestProducerBase;

class TestGlobalProducer: public TestProducerBase {
public:
	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE {
		return "test_global_producer";
	}
	
	virtual void Produce(TestEvent const& event,
			TestProduct & product,
			TestSettings const& globalSettings) const ARTUS_CPP11_OVERRIDE {
		product.iGlobalProduct = event.iVal + 5 + globalSettings.GetOffset();
	}
};

class TestGlobalProducer2: public TestProducerBase {
public:
	virtual std::string GetProducerId() const ARTUS_CPP11_OVERRIDE {
		return "test_global_producer2";
	}

	virtual void Produce(TestEvent const& event,
			TestProduct & product,
			TestSettings const& globalSettings) const ARTUS_CPP11_OVERRIDE {
		product.iGlobalProduct2 = event.iVal + 1;
	}
};
