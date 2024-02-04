#pragma once

#include <systemc-ams>

//! @brief A basic ADC model.
class BasicAdc : public sca_tdf::sca_module
{
  public:
    sca_tdf::sca_in<double> ain_p;   //! analog positive input
    sca_tdf::sca_in<double> ain_n;   //! analog negative input
    sca_tdf::sc_out<uint16_t> dout;  //! digital output

    //! @brief constructor
    //! @para name name of the sca model
    //! @para v_ref the reference voltage, default value 1.0, [unit: volt]
    //! @para res resolution, default value is 12 [unit: bits]
    //! @para fs sampling rate, default value is 100M [Hz]
    //! @para rate output port rate, default value is 1
    BasicAdc(sc_core::sc_module_name name = "adc",
             double v_ref = 1.0,
             std::uint32_t res = 12,
             std::uint32_t fs = 100e6,
             std::uint32_t rate = 1)
        : ain_p("ain_p"), ain_n("ain_n"), v_ref_(v_ref), res_(res), fs_(fs), rate_(rate)
    {
    }

  private:
    double v_ref_{};
    std::uint32_t res_{};
    std::uint32_t fs_{};
    std::uint32_t rate_{};
    std::uint32_t max_val_{};

    void set_attributes(){};

    void initialize()
    {
        //
        max_val_ = (1 << res_) - 1;
    };

    void processing()
    {
        const auto input_voltage = ain_p.read() - ain_n.read();
        auto output_val = static_cast<std::uint32_t>((input_voltage / v_ref_) * max_val_);

        output_val = std::min(output_val, max_val_);

        dout.write(output_val);
    }
};
