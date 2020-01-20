

class model
{
    private:

        IntervalVector initial_state;
        vector<IntervalVector> states;
        double period;
        vector<Function> modes;
        double time;

    public:

        //model(){};

        model( vector<Function> modes, IntervalVector initial_state, double period)
        {
            this->initial_state = initial_state;
            this->period = period;
            this->modes = modes;
        }

        void init()
        {
            
        }

        vector<Interval> getOneStateAsVector(int id_state)
        {

        }


        vector< vector<Interval> > run(vector<Function> modes, IntervalVector W, double period)
        {
            vector< vector<Interval> > states;
            vector<Interval> temperature;
            vector<Interval> volume;

            Affine2Vector y0 = Affine2Vector(W);

            for(int i = 0; i < modes.size() ; i++)
            {
                
                ivp_ode  mode = ivp_ode(modes[i], 0.0, y0); // cambios de y0 a W
                simulation run = simulation(&mode, period, HEUN, 1e-5);
                run.run_simulation();
                y0 = *(run.list_solution_j.back().box_jnh_aff);

                for(int i = 1; i<period; i += 1)
                {
                    temperature.push_back( run.get_tight(i)[0] );
                    volume.push_back( run.get_tight(i)[1] );
                }
            }

            states.push_back(temperature);
            states.push_back(volume);

            return states;

        }


};
