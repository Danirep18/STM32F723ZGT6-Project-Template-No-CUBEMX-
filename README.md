# Brief review of the project 

This project builds a template project to start with projects based on the MCU STM32H723ZGT6. In particular case,
the board that I´m using is the FK723M1-ZGT6 V1.0 

Link: <https://es.aliexpress.com/item/1005005920539367.html?spm=a2g0o.productlist.main.5.383e3e18h1X8Wm&algo_pvid=692bf356-f1fa-44c8-a6ef-c3b7f4fd2f3a&algo_exp_id=692bf356-f1fa-44c8-a6ef-c3b7f4fd2f3a-4&pdp_ext_f=%7B%22order%22%3A%2239%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21MXN%21160.95%21152.90%21%21%218.46%218.04%21%402101c59117524014848951582e8ab7%2112000040588136915%21sea%21MX%210%21ABX&curPageLogUid=SVucPs5Gdgt2&utparam-url=scene%3Asearch%7Cquery_from%3A>

## Peripherals 

This template implements UART communication

* PA9 $\rightarrow$ TX
* PA10 $\rightarrow$ RX

And the clock configuration is set for: 

* SYSCLK $\rightarrow 400 \left[MHz\right]$
* HCLK $\rightarrow 200 \left[MHz\right]$
* PCLK1 $\rightarrow 100 \left[MHz\right]$
* PCLK2 $\rightarrow 100 \left[MHz\right]$
* PCLK3 $\rightarrow 100 \left[MHz\right]$
* PCLK4 $\rightarrow 100 \left[MHz\right]$

There's no code generated by CUBE MX, so feel free to initialize your low level peripherals in *msp.c* and high level peripherals in *main_init.c*

📘 Embedded Systems
