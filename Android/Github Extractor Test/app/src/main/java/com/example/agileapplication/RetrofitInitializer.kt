package com.example.agileapplication
import retrofit2.Call
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.GET
//terminar aqui, tem erros
class RetrofitInitializer {
    fun init() {
        Retrofit.Builder()
            .baseUrl("https://api.github.com/users/")
            .addConverterFactory(GsonConverterFactory.create())
            .build()
    }

    fun reposService() = Retrofit.create(ReposService::class.java)

}

interface ReposService {
    @GET("{}/repos")
    fun list() : Call<List<Repos>>
}