# Proof And Concept Of The Lange Model
**An Idea Of How Lange's Model Could Be Implemented And Used**

[![](assets/Oskar_Lange_20-65.jpg)](https://en.wikipedia.org/wiki/Oskar_R._Lange "Oskar Lange")

- [Proof And Concept Of The Lange Model](#proof-and-concept-of-the-lange-model)
  * [What Is The Lange Model?](#what-is-the-lange-model-)
  * [Context](#context)
  * [Expanding Upon The Model](#expanding-upon-the-model)
    + [Economic Monitoring](#economic-monitoring)
    + [Supply](#supply)
    + [Economic Plans](#economic-plans)
    + [Tackling Inflation](#tackling-inflation)
    + [Government Funding](#government-funding)
    + [Trading](#trading)
  * [How The Code Works](#how-the-code-works)
    + [The Two-Day System](#the-two-day-system)
    + [Data File](#data-file)
  * [Criticisms](#criticisms)
  * [THIS IS A PROOF OF CONCEPT](#this-is-a-proof-of-concept)
    + [NOT YET COMPLETED](#not-yet-completed)

## What Is The Lange Model?
> "The Lange model (or Lange–Lerner theorem) is a neoclassical economic model for a hypothetical socialist economy based on public ownership of the means of
> production and a trial-and-error approach to determining output targets and achieving economic equilibrium and Pareto efficiency. In this model, the state
> owns non-labor factors of production, and markets allocate final goods and consumer goods. The Lange model states that if all production is performed by a
> public body such as the state, and there is a functioning price mechanism, this economy will be Pareto-efficient, like a hypothetical market economy
> under perfect competition. Unlike models of capitalism, the Lange model is based on direct allocation, by directing enterprise managers to set price
> equal to marginal cost in order to achieve Pareto efficiency." —[Wikipedia, Lange Model](https://en.wikipedia.org/wiki/Lange_model)

This definition given by Wikipedia is a pretty good summary of what the Lange Model is, although I'd like to add that profits made under this system are divided socially.

Definetly read the Wikipedia on the Lange Model before advancing, and if you want more information then read "On the Economic Theory of Socialism" by Oskar Lange.

## Context
A problem of this model is the need to calculate gigantic quanitities of calculations, ableit simple calculations. This problem was argued at the time 
(1930s) by prominent economist Friedrich Hayek against the Lange Model. A couple of years have passed since the 1930s although, with the introduction of 
technology that can do the task of calculating simple equations repetiviely in a very short amount of time. This thought of using computers to carry-out 
this process was first recommended by Oskar Lange in a piece published in 1965, the same year he died sadly. Although, he didn't recommend the entire 
economy to be "decentralized" (in a way) and be automated entirely, but that computers be used as an instrument for economists to use to plan the economy.

## Expanding Upon The Model
### Economic Monitoring
To expand upon the idea of using computers as tools for the economy, I looked at the famous socialist Chilean project from the early 70's called "Project 
Cybersyn". Now, I believe that Project Cybersyn wouldn't have worked as apparently it was supposed to run a full-simulation of the Chilean economy and also 
it was the 70's in Chile, that and simulating an economy is like simulating physics. One thing I do like though about this project was how the economy would still be planned and not fully automated as there was 
still human input, as in human monitoring. To not have the economy be fully-automated and to not have the use of "economic-automation" be painfully slow, 
we could use human monitoring of prices, suggested by the computers, to have the economy still be planned, and at least maintained by humans. Once, a review reading and possible changes to price-changes or price-info is concluded, prices are changed by the Central Planning Board and not the computers.

### Supply
For this model to work, technology for tracking supply available would be needed. The supply tracked wouldn't have to be so specific, but the less 
rounded data there is, the better essentially. The USSR was able to do this, although I haven't really looked too much into how they were so far.

### Economic Plans
To launch economic plans within this system, two known routes can be taken. One is to use the framework of the market to 
launch a plan (for example: having a plan to lower the amount of nuclear energy used and increase the amount of wind energy can be done by slowly adjusting 
the amount of nuclear energy and wind energy into the market until wanted levels are seen). The second route would be to change prices manually, although 
this would affect equilibrium.

### Tackling Inflation
Inflation could be tackled by reinvesting some of the profits that would've been divided socially to be used to increase the quality of an item via 
marginal cost.

### Government Funding
Taxes would be needed and/or a percentage of the social dividend to be taken.

### Trading
No monetary exchanges for items could happen when trading with other countries, so trading would be very traditionalistic.

## How The Code Works
The main problem against the Lange model was the non-automated trial-and-error price adjustments, so my code just simply automates those price adjustments 
needed. How it does this is by getting the data of the supply amount available, marginal cost of an item, and the price each day, and then using fuzzy 
logic to determine if the price should increase, decrease, or stay, if at an equilibrium (sort-of a fuzzy-logic dynamic pricing system). This code was 
tested on a system running Debian 11.

### The Two-Day System
The Two-Day System is basically a system that changes the price of an item every two-days until economic equilibrium is achieved.
How Data Should Be Retrieved:
1. Get only the very first day's supply early
2. Get everydays' price early
3. Get everydays' (except the very first day's) supply later

### Data File
The data file is the input file for the code with an item's market data. The file formats for this data that are accepted are .csv and .txt.

## Criticisms
Major Criticisms against this system would be the efficiency of collecting data and using it within this system. For example, this system uses the Two-Day 
System which, even with today's technology, is still a very short amount of time to get data to then change prices from. Although, the good news is that 
this model doesn't have to use the Two-Day system, and can use any day system it wants as this is all just a proof of concept. A criticism left by 
economist Milton Friendman was the silly argument about how law-enforcement would have to shut down private start-ups. While yes this often does happen in 
informal economies under socialism, a good movement for the people to be on-board against this idea of ruining the economy could be had, and also there's 
always the controlling the informal economy and making it as small as possible as there will always be an informal economy. The vague argument of this model still being unrealistic could also be said, I guess.

## THIS IS A PROOF OF CONCEPT
This entire thing is just a proof of concept at the end of the day, and the code and and everything else I supply to this repository will all just be very 
simple. For example, I am not going to be working on a system that tracks supplies, sends the data to a server to then run the code, and then makes a 
summary of important price changes, price info, marginal costs, and supply data into a pdf file to be viewed and monitored. I would just like to stress 
again, this is a proof of concept that the model could work.

### NOT YET COMPLETED
I would like to change the code from C++ to R (the economist's preferred programming language).
