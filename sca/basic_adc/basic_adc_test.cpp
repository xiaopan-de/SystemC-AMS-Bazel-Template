#include "sca/basic_adc/basic_adc.h"

#include <gtest/gtest.h>

class Stimuli : public sca_tdf::sca_module
{
  public:
    sca_tdf::sc_in<uint16_t> din;
    sca_tdf::sca_out<double> aout_p;
    sca_tdf::sca_out<double> aout_n;

    Stimuli(sc_core::sc_module_name nm) {}

    void processing()
    {
        aout_p.write(out_p_);
        aout_n.write(out_n_);
    }

    void SetOutValue(double out_p, double out_n)
    {
        out_p_ = out_p;
        out_n_ = out_n;
    }

  private:
    double out_p_{0.0};
    double out_n_{0.0};
};

class BasicAdcTest : public ::testing::Test
{
  protected:
    std::unique_ptr<BasicAdc> basic_adc;
    std::unique_ptr<Stimuli> stimuli;
    sca_tdf::sca_signal<double> a_sig1, a_sig2;
    sc_core::sc_signal<uint16_t> d_sig;

    void SetUp() override
    {
        sc_core::sc_set_time_resolution(1, sc_core::SC_NS);

        basic_adc = std::make_unique<BasicAdc>("basic_adc");
        basic_adc->ain_p(a_sig1);
        basic_adc->ain_n(a_sig2);
        basic_adc->dout(d_sig);

        stimuli = std::make_unique<Stimuli>("stimuli");
        stimuli->din(d_sig);
        stimuli->aout_p(a_sig1);
        stimuli->aout_n(a_sig2);

        stimuli->set_timestep(1, sc_core::SC_NS);
    }

    void TearDown() override {}

    void RunSim(sc_core::sc_time time = sc_core::sc_time(10, sc_core::SC_NS))
    {
        sc_core::sc_start(time);
        sc_core::sc_stop();
    }
};

TEST_F(BasicAdcTest, GivenValidAnalogInput_WhenAdcConversion_ThenCorrectConvertedinput)
{
    // given
    double stimuli_positive_out{1.0};
    double stimuli_negative_out{0.0};
    stimuli->SetOutValue(stimuli_positive_out, stimuli_negative_out);

    // when
    sc_core::sc_start(sc_core::sc_time(10, sc_core::SC_NS));

    // RunSim(sc_core::sc_time(10, sc_core::SC_NS));

    // then
    double expected_output = 4095;  // 10bit resolution
    EXPECT_EQ(d_sig.read(), expected_output);
}

int sc_main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
